Ватериус поддерживает отправку в
- сайт <a href="https://waterius.ru" target="_blank">waterius.ru</a>
- в Home Assistant по MQTT
- в WirenBoard по MQTT
- MQTT
- HTTP

Отправка в MQTT и HTTP происходит при каждом пробуждении устройства.

# Список параметров
В таблице собрана информация об отправляемых данных. В столбцах HTTP, MQTT, Blynk указано, отправляются ли данные по соответствующему протоколу. В столбце Blynk указан номер виртуального пина в который записывается поле.

Вход 0 - Синий
Вход 1 - Красный

| Поле | Размерность | Тип | Описание | HTTP | MQTT | С версии | 
| --- | --- | --- | --- | --- | --- | --- |
| adc0 | - | uint | Аналоговый уровень входа 0 | + | + | - |
| adc1 | - | uint | Аналоговый уровень входа 1 | + | + | - |
| boot | - | uint | Причина загрузки attiny85 | + | + | - |
| battery | - | int | % заряда батарейки (фейковый) | + | + | - |
| blynk | - | bool | сервер blynk заполнен | + | + | - |
| ch0 | м3 | float | Показания воды, вход 0 | + | + | - |
| ch1 | м3 | float | Показания воды, вход 1 | + | + | - |
| ch0_start | м3 | float | Начальные показания воды, вход 0 | + | + | - |
| ch1_start | м3 | float | Начальные показания воды, вход 1 | + | + | - |
| channel | - | int | Канал wi-fi роутера | + | + | - |
| cname0 | - | uint | Тип счётчика, вход 0 | + | + | - |
| cname1 | - | uint | Тип счётчика, вход 1 | + | + | - |
| data_type0 | - | uint | Тип данных, вход 0 | + | + | - |
| data_type1 | - | uint | Тип данных, вход 1 | + | + | - |
| dhcp | - | bool | DHCP включен | + | + | - |
| delta0 | литр | uint | Разница с предыдущими показаниями, вход 0 (гор. вода) | + | + | - | 
| delta1 | литр | uint | Разница с предыдущими показаниями, вход 1 (хол. вода) | + | + | - | 
| email | - | str | Электронная почта | + | + | - |
| esp_id | - | int | Серийный номер ESP | + | + | - |
| f0 | - | uint | Вес импульса, вход 0 | + | + | - |
| f1 | - | uint | Вес импульса, вход 1 | + | + | - |
| freemem | - | int | свободная память в ESP, байт | + | + | - |
| good | - | uint | Получены данные от attiny85. Всегда 1. | + | + | - |
| imp0 | шт | uint | Количество импульсов | + | + | V0 | 
| imp1 | шт | uint | Количество импульсов | + | + | V1 | 
| itype0 | - | uint | Тип чтения, вход 0 | + | + | - | 
| itype1 | - | uint | Тип чтения, вход 1 | + | + | - | 
| ip | - | str | ip адрес локальный ESP (Х.Х.Х.Х) | + | + | - |
| ha | - | bool | флаг HA дискавери включен | + | + | - |
| key | - | str | Уникальный токен | + | - | - |
| mac | - | str | MAC адрес ESP (ХХ:ХХ:ХХ:ХХ:ХХ:ХХ) | + | + | - |
| mode | - | int | Режим пробуждения 2-авто, 3-по кнопке | + | + | - |
| mqtt | - | bool | брокер mqtt заполнен | + | + | - |
| period_min | минуты | uint | Период пробуждения | + | + | - |
| resets | шт | uint | Количество перезагрузок | + | + | V5 |
| router_mac | - | str | MAC адрес производителя роутера (ХХ:ХХ:ХХ:00:00:00) | + | + | - |
| rssi | dBm | int | Уровень Wi-Fi сигнала | + | + | V8 |
| setup_finished | - | int | число успешных подключений к роутеру после настройки | + | + | - |
| setup_started | - | int | число включений режима настройки | + | + | - |
| setuptime | мсек | int | Длительность режима настройки | + | + | - |
| serial0 | - | str | Серийный номер, вход 0 | + | + | - |
| serial1 | - | str | Серийный номер, вход 1 | + | + | - |
| timestamp | - | str | Текущая дата и время 2019-11-29T23:29:55+0800 | + | + | - |
| version | - | int | Версия прошивки attiny85 | + | + | - |
| version_esp | - | str | Версия прошивки esp | + | + | - |
| voltage | В | float | Напряжение питания attiny85 | + | + | - |
| voltage_diff | мВ | int | Просадка напряжения за время подключения Wi-Fi | + | + | - |
| voltage_low | 0 или 1 | int | voltage_diff выше 50мВ  | + | + | - |
| waketime | мсек | int | Время работы ESP при предыдущем включении | + | + | - |
| wifi_phy_mode | - | str | Текущий режим Wi-Fi | + | + | - |
| wifi_phy_mode_s | - | str | Режим Wi-Fi из настроек | + | + | - |
| company | - | str(20) | ИНН организации-установщика | + | + | 1.1.5 |
| place | - | str(20) | Место установки | + | + | 1.1.5 |


#### cnameX
| Тип счетчика | Описание |
| --- | --- |
| 0 | Холодная вода |
| 1 | Горячая вода |
| 2 | Электричество |
| 3 | Газ |
| 4 | Тепло |
| 5 | Питьевая вода |
| 6 | Другой |

#### data_typeX
| Тип данных | Описание |
| --- | --- |
| 0 | Холодная вода |
| 1 | Горячая вода |
| 2 | Электричество |
| 3 | Газ |
| 4 | Тепло |
| 9 | Питьевая вода |
| 10 | Другой |

#### itypeX
| Тип чтения | Описание | Описание |
| --- | --- | --- |
| 0 | Намур | Для механических счетчиков |
| 1 | Дискретный | Для механических счетчиков (убрал) |
| 2 | Электронный | Для электронных счетчиков |


# Настройка отправки на сайт waterius.ru
Зарегистрируйтесь на сайте waterius.ru по адресу электронной почты.
Заполните в режиме настройки:
| Поле | Описание | Пример | Обязательно |
| --- | --- | --- | --- |
| Электронная почта с сайта waterius.ru | Указанная при регистрации почта | user@mail.ru | + |

Ватериус появится в личном кабинете при отправке показаний.

# Настройка отправки в Home Assistant по MQTT 

Заполненное поле "Адрес сервера" включает отправку по протоколу MQTT.
Для подключения нескольких ватериусов укажите им разные топики.
Обязательно включить параметр "retained" на брокере. 
Данные отправляются с retain=true

С версии 0.11.0: По умолчанию данные прилетят в виде JSON (при включенном параметре discovery) в топик. (Например: "waterius/12380568/")

```
{"delta0":0,"delta1":0,"ch0":338.304,"ch1":535.966,"imp0":79,"imp1":109,"f0":10,"f1":10,"adc0":113,"adc1":114,"serial0":"","serial1":"","itype0":0,"itype1":0,"cname0":1,"cname1":0,"data_type0":1,"data_type1":0,"voltage":3.128,"voltage_low":true,"voltage_diff":0.21,"battery":0,"channel":12,"router_mac":"AA:AA:AA:00:00:00","rssi":-70,"mac":"E8AAAA:AA:AA:AA:AA","ip":"172.16.64.50","dhcp":true,"version":31,"version_esp":"0.11.9","esp_id":8686250,"freemem":37504,"timestamp":"2023-10-22T17:01:10+0000","waketime":10829,"period_min":1440,"setuptime":91781,"good":1,"boot":1,"resets":1,"mode":3,"setup_finished":4,"setup_started":5,"key":"AA","email":"AA@ya.ru","mqtt":true,"blynk":true,"ha":false}
```
Если параметр discovery выключен или версия прошивки <0.11.0, то данные отправятся в виде отдельных топиков:
```
waterius/12380568/version_esp 0.10.0
waterius/12380568/version 13
waterius/12380568/ch0 0.100
waterius/12380568/ch1 11.200
waterius/12380568/f0 10
waterius/12380568/resets 7
waterius/12380568/rssi -69
и т.д.
```

Заполните в режиме настройки:
| Поле | Описание | Пример | Обязательно |
| --- | --- | --- | --- |
| Адрес сервера | ip адрес брокера или домен | 192.168.1.10, broker.hivemq.com | + |
| Порт | порт брокера | 1883 | + |
| Логин | логин для авторизированного доступа | username | - |
| Пароль | пароль для авторизированного доступа | secret | - |
| Топик | топик по которому будут отсылаться данные | waterius/123456/ | + |
| discovery | обязателен, чтобы работал discovery  | - | + |
| Топик для discovery | топик по которому будут отсылаться данные | homeassistant | + |

С версии 0.11.0 доступно менять параметр period_min, c 0.11.9 и некоторые другие.

| параметр   | топик для записи                   | тип данных    | пример топика                     | пример данных | версия    |
|------------|------------------------------------|---------------|-----------------------------------|---------------|-----------|
| period_min | <топик из настроек>/period_min/set | целое число   | waterius/124121251/period_min/set | 60            | >=0.11.0  |
| f0         | <топик из настроек>/f0/set         | целое число   | waterius/124121251/f0/set         | 10            | >=0.11.9  |
| f1         | <топик из настроек>/f1/set         | целое число   | waterius/124121251/f1/set         | 10            | >=0.11.9  |
| ch0        | <топик из настроек>/ch0/set        | дробное число | waterius/124121251/ch0/set        | 121.4         | >=0.11.9  |
| ch1        | <топик из настроек>/ch1/set        | дробное число | waterius/124121251/ch1/set        | 151.53        | >=0.11.9  |
| cname0     | <топик из настроек>/cname0/set     | целое число   | waterius/124121251/cname0/set     | 0             | >=1.0.2   |
| cname1     | <топик из настроек>/cname1/set     | целое число   | waterius/124121251/cname1/set     | 0             | >=1.0.2   |
| itype0     | <топик из настроек>/itype0/set     | целое число   | waterius/124121251/itype0/set     | 0             | >=1.0.2   |
| itype1     | <топик из настроек>/itype1/set     | целое число   | waterius/124121251/itype1/set     | 0             | >=1.0.2   |

Примечание: значения itype0, itype1 указано выше в разделе itypeX
Примечание: значения cname0, cname1 указано выше в разделе cnameX

# Настройка отправки в WirenBoard по MQTT 

Выполните настройки MQTT как для отправки в Home Assistant.

Загрузите скрипт ![waterius_wirenboard.js](https://github.com/dontsovcmc/waterius/raw/master/waterius_wirenboard.js)
 в WirenBoard и измените в нём topic.


# Настройка отправки по HTTP (свой сервер)

Заполните в режиме настройки:
| Поле | Описание | Пример | Обязательно |
| --- | --- | --- | --- |
| Адрес сервера | ip адрес сервера или домен (```http[s]://host[:port][/path]```) | 192.168.1.10, http://mysite.ru, http://mysite.ru:1000/data | + |

Если "Адрес сервера" пустой, отправка по HTTP выключена.

Ватериус отправляет POST запрос с данными в виде JSON.

<a href="https://github.com/dontsovcmc/waterius/wiki/%D0%9F%D1%80%D0%B8%D0%BC%D0%B5%D1%80-%D0%B2%D0%B5%D0%B1%D1%81%D0%B5%D1%80%D0%B2%D0%B5%D1%80%D0%B0">Пример вебсервера</a>

## Поддержка HTTPS 

Добавлена библиотека BearSSL с поддержкой TLS 1.2 шифрования.
Если ваш сервер https, то требуется пересобрать прошивку с вашим сертификатом удостоверящего центра. Инструкция по созданию сертификатов в [Python скрипте]. У сертификатов есть срок действия.

# Проекты сообщества
* [httpwaterius](https://github.com/grffio/httpwaterius) - web сервер с простым UI от [grffio](https://github.com/grffio)
