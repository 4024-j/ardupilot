/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_AHRS/AP_AHRS.h>
#include <AP_SerialManager/AP_SerialManager.h>



class AP_Rpi_USAT {
public:
    AP_Rpi_USAT();

    /* Do not allow copies */
    AP_Rpi_USAT(const AP_Rpi_USAT &other) = delete;
    AP_Rpi_USAT &operator=(const AP_Rpi_USAT&) = delete;

    // init - perform required initialisation
    //bool init();

    void init(const AP_SerialManager& serial_manager);

        // update flight control mode. The control mode is vehicle type specific
        void update(void);

        uint8_t cx;
        uint8_t cy;
        uint8_t cz;

        uint32_t last_frame_ms;

private:
    AP_HAL::UARTDriver *_port;                  // UART used to send data to FrSky receiver


    uint8_t _step;

        uint8_t _cx_temp;
        uint8_t _cy_temp;
        uint8_t _cz_temp;

    
};
