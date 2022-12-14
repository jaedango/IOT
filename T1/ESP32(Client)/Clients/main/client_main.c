/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */
#include "esp_log.h"     
#include "nvs_flash.h"
#include "esp_netif.h"
#include "protocol_examples_common.h"
#include "esp_event.h"


extern void tcp_udp_client(void);
static const char *TAG21 = "example";

void app_main(void)

{

    ESP_ERROR_CHECK(nvs_flash_init());
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    
    // /* This helper function configures Wi-Fi or Ethernet, as selected in menuconfig.
    //  * Read "Establishing Wi-Fi or Ethernet Connection" section in
    //  * examples/protocols/README.md for more information about this function.
    //  */
    ESP_ERROR_CHECK(example_connect());


    
    // if no hay configuracion prender bluetooth y recuperar informacion


    
    //else Recuperar información en memoria no volatil

    
    // De acuerdo a informacion en no volatil ejecutar wifi o bluetooth.

    ESP_LOGI(TAG21, "=====Ejecutando tcp_udp_client...=====");
    tcp_udp_client(); 
    // llamar a blutu

}
