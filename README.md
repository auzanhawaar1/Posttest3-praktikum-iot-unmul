# Posttest3-praktikum-iot-unmul

## Kelompok 2 B 21 :
1. 2109106127 - Auzan Hawaari Fahrony
2. 2109106134 - Abdullah Mustaqim
3. 2109106142 - Galuh Endah Pambudi

## Rangkaian LED, Piezzo Buzzer, dan DHT11 dengan Blynk sebagai monitoring value
Deskripsi: Proyek ini bertujuan untuk membuat sebuah sistem IoT yang menggunakan mikrokontroler ESP8266 untuk mengontrol suhu dengan menggunakan sebuah LED dan Pizzeo Buzzer,yang mengambil data dari sensor DHT11, dan mengintegrasikan semua informasi ini ke dalam dashboard Blynk. Pada proyek ini, hasil deteksi dari sensor DHT11 akan dikonversikan menjadi Celsius, Fahrenheit, dan Kelvin, dan ditampilkan pada Blynk untuk melihat value dht11.

Cara Kerja Alat: Pada proyek ini, DHT11 digunakan untuk mengambil atau mengukur suhu di sekitar. Setelah nilai suhu didapatkan, program akan memeriksa apakah suhu berada di bawah 30°C. Jika ya, lampu hijau akan menyala, sementara lampu merah dan kuning akan dimatikan, dan piezo buzzer akan diam. Jika suhu berada dalam rentang 30°C hingga 36°C, lampu kuning akan menyala, sementara lampu merah dan hijau akan dimatikan, dan piezo buzzer akan diam. Jika suhu berada di atas 36°C, lampu merah akan menyala, sementara lampu kuning dan hijau akan dimatikan, dan piezo buzzer akan berbunyi. Setelah DHT11 membaca suhu, nilai suhu akan dikirimkan ke Blynk untuk membaca datanya.

## Pembagian Tugas :
1. Abdullah Mustaqim : Membuat struktur coding dan mengatur konfigurasi Bylnk. 
2. Auzan Hawaari Fahrony : Menyusun rangkaian komponen LED, Piezzo Buzzer dan NodeMCU 
3. Galuh Endah Pambudi : Asisten merangkai dan coding

## Komponen Yang digunakan : 
1.ESP8266
2.Kabel Jumper
3.Piezzo Buzzer
4.DHT11
5.LED
6.Resistor
7.Breadboard
8.Kabel MicroUSB

## Design Schematic :

![WhatsApp Image 2024-03-21 at 11 22 38](https://github.com/auzanhawaar1/Posttest3-praktikum-iot-unmul/assets/113401118/3fed7a5d-35ea-4579-8595-022dbaef538e)


## Scematic Kami :

![WhatsApp Image 2024-03-21 at 11 22 21](https://github.com/auzanhawaar1/Posttest3-praktikum-iot-unmul/assets/113401118/64d0d401-0cf8-40e2-b3a4-9e59f2ec0f68)

