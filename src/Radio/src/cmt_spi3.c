#include "cmt_spi3.h"
#include "./../../gpio.h"

void cmt_spi3_delay(void)
{
    uint32_t n = 8;
    while (n--)
        ;
}

void cmt_spi3_delay_us(void)
{
    uint16_t n = 8;
    while (n--)
        ;
}

void cmt_spi3_init(void)
{
    spi_gpio_init();
    cmt_spi3_sda_in();
    cmt_spi3_delay();
}

void cmt_spi3_send(uint8_t data8)
{
    uint8_t i;

    for (i = 0; i < 8; i++)
    {
        cmt_spi3_scl_0();

        /* Send byte on the rising edge of SCL */
        if (data8 & 0x80)
            cmt_spi3_sda_1();
        else
            cmt_spi3_sda_0();

        cmt_spi3_delay();

        data8 <<= 1;
        cmt_spi3_scl_1();
        cmt_spi3_delay();
    }
}

uint8_t cmt_spi3_recv(void)
{
    uint8_t i;
    uint8_t data8 = 0xFF;

    for (i = 0; i < 8; i++)
    {
        cmt_spi3_scl_0();
        cmt_spi3_delay();
        data8 <<= 1;

        cmt_spi3_scl_1();

        /* Read byte on the rising edge of SCL */
        if (cmt_spi3_sda_read())
            data8 |= 0x01;
        else
            data8 &= ~0x01;

        cmt_spi3_delay();
    }

    return data8;
}

void cmt_spi3_write(uint8_t addr, uint8_t dat)
{
    cmt_spi3_sda_out();
    cmt_spi3_sda_1();

    cmt_spi3_scl_0();
    //    cmt_spi3_scl_out();
    cmt_spi3_scl_0();

    cmt_spi3_fcsb_1();
    //    cmt_spi3_fcsb_out();
    cmt_spi3_fcsb_1();

    cmt_spi3_csb_0();

    /* > 0.5 SCL cycle */
    cmt_spi3_delay();
    cmt_spi3_delay();

    /* r/w = 0 */
    cmt_spi3_send(addr & 0x7F);

    cmt_spi3_send(dat);

    cmt_spi3_scl_0();

    /* > 0.5 SCL cycle */
    cmt_spi3_delay();
    cmt_spi3_delay();

    cmt_spi3_csb_1();

    cmt_spi3_sda_1();
    cmt_spi3_sda_in();

    cmt_spi3_fcsb_1();
}

void cmt_spi3_read(uint8_t addr, uint8_t *p_dat)
{
    cmt_spi3_sda_out();
    cmt_spi3_sda_1();

    cmt_spi3_scl_0();
    //    cmt_spi3_scl_out();
    cmt_spi3_scl_0();

    cmt_spi3_fcsb_1();
    //    cmt_spi3_fcsb_out();
    cmt_spi3_fcsb_1();

    cmt_spi3_csb_0();

    /* > 0.5 SCL cycle */
    cmt_spi3_delay();
    cmt_spi3_delay();

    /* r/w = 1 */
    cmt_spi3_send(addr | 0x80);

    /* Must set SDA to input before the falling edge of SCL */
    cmt_spi3_sda_in();

    *p_dat = cmt_spi3_recv();

    cmt_spi3_scl_0();

    /* > 0.5 SCL cycle */
    cmt_spi3_delay();
    cmt_spi3_delay();

    cmt_spi3_csb_1();

    cmt_spi3_sda_1();
    cmt_spi3_sda_in();

    cmt_spi3_fcsb_1();
}

void cmt_spi3_write_fifo(const uint8_t *p_buf, uint16_t len)
{
    uint16_t i;

    cmt_spi3_fcsb_1();
    //    cmt_spi3_fcsb_out();
    cmt_spi3_fcsb_1();

    cmt_spi3_csb_1();
    //    cmt_spi3_csb_out();
    cmt_spi3_csb_1();

    cmt_spi3_scl_0();
    //    cmt_spi3_scl_out();
    cmt_spi3_scl_0();

    cmt_spi3_sda_out();

    for (i = 0; i < len; i++)
    {
        cmt_spi3_fcsb_0();

        /* > 1 SCL cycle */
        cmt_spi3_delay();
        cmt_spi3_delay();

        cmt_spi3_send(p_buf[i]);

        cmt_spi3_scl_0();

        /* > 2 us */
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();

        cmt_spi3_fcsb_1();

        /* > 4 us */
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
    }

    cmt_spi3_sda_in();

    cmt_spi3_fcsb_1();
}

void cmt_spi3_read_fifo(uint8_t *p_buf, uint16_t len)
{
    uint16_t i;

    cmt_spi3_fcsb_1();
    //    cmt_spi3_fcsb_out();
    cmt_spi3_fcsb_1();

    cmt_spi3_csb_1();
    //    cmt_spi3_csb_out();
    cmt_spi3_csb_1();

    cmt_spi3_scl_0();
    //    cmt_spi3_scl_out();
    cmt_spi3_scl_0();

    cmt_spi3_sda_in();

    for (i = 0; i < len; i++)
    {
        cmt_spi3_fcsb_0();

        /* > 1 SCL cycle */
        cmt_spi3_delay();
        cmt_spi3_delay();

        p_buf[i] = cmt_spi3_recv();

        cmt_spi3_scl_0();

        /* > 2 us */
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();

        cmt_spi3_fcsb_1();

        /* > 4 us */
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
        cmt_spi3_delay_us();
    }

    cmt_spi3_sda_in();

    cmt_spi3_fcsb_1();
}
