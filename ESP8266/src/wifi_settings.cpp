
#include "wifi_settings.h"
#include "Logging.h"

#include "Blynk/BlynkConfig.h"
#include <IPAddress.h>
#include <EEPROM.h>
#include "utils.h"

/* Сохраняем конфигурацию в EEPROM */
void storeConfig(const Settings &sett) 
{
    EEPROM.begin( 512 );

    EEPROM.put(0, sett);
    
    if (!EEPROM.commit())
    {
        LOG_ERROR("WIF", "Config stored FAILED");
    }
    else
    {
        LOG_NOTICE("WIF", "Config stored OK");
    }
}


/* Загружаем конфигурацию в EEPROM. true - успех. */
bool loadConfig(struct Settings &sett) 
{
    EEPROM.begin( 512 );

    EEPROM.get(0, sett);

    if (sett.crc == FAKE_CRC)  // todo: сделать нормальный crc16
    {
        // Для безопасной работы с буферами, т.к. нигде в библиотеках нет проверок
        sett.key[KEY_LEN-1] = '\0';
        sett.hostname[HOSTNAME_LEN-1] = '\0';
        sett.email[EMAIL_LEN-1] = '\0';
        sett.email_title[EMAIL_TITLE_LEN-1] = '\0';
        sett.email_template[EMAIL_TEMPLATE_LEN-1] = '\0'; 
        
        LOG_NOTICE( "WIF", " email=" << sett.email  << ", hostname=" << sett.hostname);

        // Всегда одно и тоже будет
        LOG_NOTICE( "WIF", "channel0_start=" << sett.channel0_start << ", impules0_start=" << sett.impules0_start << ", factor=" << sett.liters_per_impuls );
        LOG_NOTICE( "WIF", "channel1_start=" << sett.channel1_start << ", impules1_start=" << sett.impules1_start);
        
        return true;
    }
    else 
    {    // Конфигурация не была сохранена в EEPROM, инициализируем с нуля
        LOG_NOTICE( "WIF", "crc failed=" << sett.crc );

        // Заполняем нулями всю
        memset(&sett, 0, sizeof(sett));

        sett.version = CURRENT_VERSION;  //для совместимости в будущем
        sett.liters_per_impuls = LITRES_PER_IMPULS_DEFAULT;
        
        String hostname = BLYNK_DEFAULT_DOMAIN;
        strncpy0(sett.hostname, hostname.c_str(), HOSTNAME_LEN);

        String email_title = "New values {DEVICE_NAME}";
        strncpy0(sett.email_title, email_title.c_str(), EMAIL_TITLE_LEN);

        String email_template = "Hot: {V0} m3, Cold: {V1} m3<br>day:<br>hot: +{V3}, cold: +{V4}<br>power:{V2}";
        strncpy0(sett.email_template, email_template.c_str(), EMAIL_TEMPLATE_LEN);

        LOG_NOTICE("WIF", "version=" << sett.version << ", hostname=" << hostname);
        return false;
    }
}
         