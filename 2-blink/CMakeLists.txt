cmake_minimum_required(VERSION 3.22)
set(BOARD esp_wrover_kit)

find_package(Zephyr)
project(hello_world_blinky)

target_sources(app PRIVATE src/main.c)