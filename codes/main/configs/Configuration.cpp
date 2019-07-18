/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Configuration.h"
#include "../systems/Engine.h"
#include <string>
#include <QString>
#include <QDir>
#include <QDebug>
using std::to_string;
#define log Engine::getInstance()->getLogger()

/**
 * Configuration implementation
 */

bool Configuration::isInit = false;

shared_ptr<Configuration> Configuration::config = nullptr;

Configuration::Configuration(const string file) {
    this->file = file;
    reload();
}

Configuration::~Configuration() {
}

shared_ptr<Configuration> Configuration::getInstance() {
    if(!isInit){
        config = shared_ptr<Configuration>(new Configuration("../../../config.yml"));
        isInit = true;
    }
    return config;
}

void Configuration::reload() {
    log->information("开始读取config");
    bool defaultMode = false;
    root = YAML::LoadFile(file);
    log->information("读取loop配置项");
    long timePerTick = 50, allowMaxTick = 200;
    int allowWaitTime = 500, playerNumber = 2;
    if(!defaultMode){
        timePerTick = root["loop"]["timePerTick"].as<long>();
        allowMaxTick = root["loop"]["allowMaxTick"].as<long>();
    }
    shared_ptr<LoopConfiguration> loopConfig =
            shared_ptr<LoopConfiguration>(new LoopConfiguration(allowMaxTick, milliseconds(timePerTick)));
    if(!defaultMode){
        allowWaitTime = root["loop"]["allowWaitTime"].as<int>();
        playerNumber = root["loop"]["playerNumber"].as<int>();
    }
    shared_ptr<JudgerConfiguration> judgerConfig =
            shared_ptr<JudgerConfiguration>(new JudgerConfiguration(allowWaitTime));
    log->information("读取map配置项");
    int height = 500, width = 500, maxAllowPlayer = 2;
    Point2D ps[2] = {Point2D(75, 75), Point2D(425, 425)};
    if(!defaultMode){
        height = root["map"]["height"].as<int>();
        width = root["map"]["width"].as<int>();
        maxAllowPlayer = root["map"]["maxAllowPlayer"].as<int>();
        for(int i=1; i<=maxAllowPlayer; ++i){
            double x = root["map"]["birthPlaces"][to_string(i)]["x"].as<double>();
            double y = root["map"]["birthPlaces"][to_string(i)]["y"].as<double>();
            ps[i-1] = Point2D(x, y);
        }
    }
    shared_ptr<MapConfiguration> mapConfig =
            shared_ptr<MapConfiguration>(new MapConfiguration(height, width, maxAllowPlayer, ps));
    log->information("读取carrier配置项");
    int health = 2000, healRate = 0, healPower = 0;
    double speed = 0.1, radius = 30, sightAngle = 0.6, longSight = 100, shortSight = 50;;
    log->debug("读取carrier normal配置项");
    if(!defaultMode){
        health = root["carrier"]["normal"]["health"].as<int>();
        speed = root["carrier"]["normal"]["speed"].as<double>();
        radius = root["carrier"]["normal"]["radius"].as<double>();
        healRate = root["carrier"]["normal"]["healRate"].as<int>();
        healPower = root["carrier"]["normal"]["healPower"].as<int>();
        sightAngle = root["carrier"]["normal"]["sightAngle"].as<double>();
        longSight = root["carrier"]["normal"]["longSight"].as<double>();
        shortSight  = root["carrier"]["normal"]["shortSight"].as<double>();
    }
    log->debug("读取carrier weapon配置项");
    double weapon_radius = 10, bullet_speed = 5;
    int damage = 60, delay = 100;
    if(!defaultMode){
        weapon_radius = root["carrier"]["weapon"]["radius"].as<double>();
        bullet_speed = root["carrier"]["weapon"]["speed"].as<double>();
        damage = root["carrier"]["weapon"]["damage"].as<int>();
        delay = root["carrier"]["weapon"]["cd"].as<int>();
    }
    log->debug("读取carrier nuke配置项");
    int aoeDamage = 2000, damageDecrease=20;
    double aoeRadius = 100, nuke_radius = 50, nuke_speed = 5;
    if(!defaultMode){
        aoeDamage = root["carrier"]["nuke"]["aoeDamage"].as<int>();
        aoeRadius = root["carrier"]["nuke"]["aoeRadius"].as<double>();
        damageDecrease = root["carrier"]["nuke"]["damageDecrease"].as<int>();
        nuke_radius = root["carrier"]["nuke"]["radius"].as<double>();
        nuke_speed = root["carrier"]["nuke"]["speed"].as<double>();
    }
    shared_ptr<CarrierConfiguration> carrierConfig =
            shared_ptr<CarrierConfiguration>(new CarrierConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(weapon_radius, damage, bullet_speed, delay)),
                shared_ptr<NukeConfiguration>(new NukeConfiguration(aoeDamage, aoeRadius, damageDecrease, nuke_radius, nuke_speed)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(health, speed, radius, healRate, healPower, sightAngle, longSight, shortSight))));
    log->information("读取bomber配置项");
    int b_health = 500, b_healRate = 1, b_healPower = 20;
    double b_speed = 0.5, b_radius = 10, b_sightAngle = 0.4, b_longSight = 80, b_shortSight = 40;
    if(!defaultMode){
        b_health = root["bomber"]["normal"]["health"].as<int>();
        b_speed = root["bomber"]["normal"]["speed"].as<double>();
        b_radius = root["bomber"]["normal"]["radius"].as<double>();
        b_healRate = root["bomber"]["normal"]["healRate"].as<int>();
        b_healPower = root["bomber"]["normal"]["healPower"].as<int>();
        b_sightAngle = root["bomber"]["normal"]["sightAngle"].as<double>();
        b_longSight = root["bomber"]["normal"]["longSight"].as<double>();
        b_shortSight  = root["bomber"]["normal"]["shortSight"].as<double>();
    }
    double b_weapon_radius = 10, b_bullet_speed = 10;
    int b_damage = 80, b_delay = 50;
    if(!defaultMode){
        b_weapon_radius = root["bomber"]["weapon"]["radius"].as<double>();
        b_bullet_speed = root["bomber"]["weapon"]["speed"].as<double>();
        b_damage = root["bomber"]["weapon"]["damage"].as<int>();
        b_delay = root["bomber"]["weapon"]["cd"].as<int>();
    }
    shared_ptr<BomberConfiguration> bomberConfig =
            shared_ptr<BomberConfiguration>(new BomberConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(b_weapon_radius, b_damage, b_bullet_speed, b_delay)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(b_health, b_speed, b_radius, b_healRate, b_healPower, b_sightAngle, b_longSight, b_shortSight))));
    log->information("读取fighter配置项");
    int f_health = 200, f_healRate = 5, f_healPower = 5;
    double f_speed = 5, f_radius = 10, f_sightAngle = 0.2, f_longSight = 40, f_shortSight = 20;
    if(!defaultMode){
        f_health = root["fighter"]["normal"]["health"].as<int>();
        f_speed = root["fighter"]["normal"]["speed"].as<double>();
        f_radius = root["fighter"]["normal"]["radius"].as<double>();
        f_healRate = root["fighter"]["normal"]["healRate"].as<int>();
        f_healPower = root["fighter"]["normal"]["healPower"].as<int>();
        f_sightAngle = root["fighter"]["normal"]["sightAngle"].as<double>();
        f_longSight = root["fighter"]["normal"]["longSight"].as<double>();
        f_shortSight = root["fighter"]["normal"]["shortSight"].as<double>();
    }
    double f_weapon_radius = 2, f_bullet_speed = 20;
    int f_damage = 20, f_delay = 10;
    if(!defaultMode){
        f_weapon_radius = root["fighter"]["weapon"]["radius"].as<double>();
        f_bullet_speed = root["fighter"]["weapon"]["speed"].as<double>();
        f_damage = root["fighter"]["weapon"]["damage"].as<int>();
        f_delay = root["fighter"]["weapon"]["cd"].as<int>();
    }
    int rebuild_tick = 200, rebuild_power = 100;
    if(!defaultMode){
        rebuild_tick = root["fighter"]["rebuild"]["tick"].as<int>();
        rebuild_power = root["fighter"]["rebuild"]["power"].as<int>();
    }
    shared_ptr<FighterConfiguration> fighterConfig =
            shared_ptr<FighterConfiguration>(new FighterConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(f_weapon_radius, f_damage, f_bullet_speed, f_delay)),
                shared_ptr<RebuildableConfiguration>(new RebuildableConfiguration(rebuild_power, rebuild_tick)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(f_health, f_radius, f_speed, f_healRate, f_healPower, f_sightAngle, f_longSight, f_shortSight))));
    shared_ptr<PlayerConfiguration> playerConfig = shared_ptr<PlayerConfiguration>(new PlayerConfiguration(carrierConfig, bomberConfig, fighterConfig));
    log->information("读取littlestar配置项");
    int little_power = 20, little_radius = 3, little_collectTick = 10;
    if(!defaultMode){
        little_power = root["littleStar"]["power"].as<int>();
        little_radius = root["littleStar"]["radius"].as<int>();
        little_collectTick = root["littleStar"]["collectTick"].as<int>();
    }
    shared_ptr<LittleStarConfiguration> littleConfig = shared_ptr<LittleStarConfiguration>(new LittleStarConfiguration(little_power, little_radius, little_collectTick));
    log->information("读取largestar配置项");
    int large_power = 40, large_radius = 5, large_collectTick = 20;
    if(!defaultMode){
        little_power = root["largeStar"]["power"].as<int>();
        little_radius = root["largeStar"]["radius"].as<int>();
        little_collectTick = root["largeStar"]["collectTick"].as<int>();
    }
    shared_ptr<LargeStarConfiguration> largeConfig = shared_ptr<LargeStarConfiguration>(new LargeStarConfiguration(large_power, large_radius, large_collectTick));
    this->gameConfig = shared_ptr<GameConfiguration>(new GameConfiguration(mapConfig, judgerConfig, loopConfig, playerNumber, playerConfig, largeConfig, littleConfig));
    if(defaultMode){
        writeToYaml();
    }
}

void Configuration::setDefault(){
     log->information("重置配置项...");
     root["loop"]["timePerTick"] = 50;
     root["loop"]["allowMaxTick"] = 200;
     root["loop"]["allowWaitTime"] = 500;
     root["loop"]["playerNumber"] = 2;
     root["map"]["height"] = 500;
     root["map"]["width"] = 500;
     root["map"]["maxAllowPlayer"] = 2;
     root["map"]["birthPlaces"]["1"]["x"] = 75;
     root["map"]["birthPlaces"]["1"]["y"] = 75;
     root["map"]["birthPlaces"]["2"]["x"] = 425;
     root["map"]["birthPlaces"]["2"]["y"] = 425;
     root["carrier"]["normal"]["health"] = 2000;
     root["carrier"]["normal"]["speed"] = 0.1;
     root["carrier"]["normal"]["radius"] = 30;
     root["carrier"]["normal"]["healRate"] = 0;
     root["carrier"]["normal"]["healPower"] = 0;
     root["carrier"]["normal"]["sightAngle"] = 0.6;
     root["carrier"]["normal"]["longSight"] = 100;
     root["carrier"]["normal"]["shortSight"] = 50;
     root["carrier"]["weapon"]["radius"] = 10;
     root["carrier"]["weapon"]["speed"] = 60;
     root["carrier"]["weapon"]["damage"] = 5;
     root["carrier"]["weapon"]["cd"] = 100;
     root["carrier"]["nuke"]["aoeDamage"] = 2000;
     root["carrier"]["nuke"]["aoeRadius"] = 100;
     root["carrier"]["nuke"]["damageDecrease"] = 20;
     root["carrier"]["nuke"]["radius"] = 50;
     root["carrier"]["nuke"]["speed"] = 5;
     root["bomber"]["normal"]["health"] = 500;
     root["bomber"]["normal"]["speed"] = 0.5;
     root["bomber"]["normal"]["radius"] = 10;
     root["bomber"]["normal"]["healRate"] = 1;
     root["bomber"]["normal"]["healPower"] = 20;
     root["bomber"]["normal"]["sightAngle"] = 0.4;
     root["bomber"]["normal"]["longSight"] = 120;
     root["bomber"]["normal"]["shortSight"] = 80;
     root["bomber"]["weapon"]["radius"] = 10;
     root["bomber"]["weapon"]["speed"] = 80;
     root["bomber"]["weapon"]["damage"] = 10;
     root["bomber"]["weapon"]["cd"] = 50;
     root["fighter"]["normal"]["health"] = 200;
     root["fighter"]["normal"]["speed"] = 5;
     root["fighter"]["normal"]["radius"] = 10;
     root["fighter"]["normal"]["healRate"] = 5;
     root["fighter"]["normal"]["healPower"] = 5;
     root["fighter"]["normal"]["sightAngle"] = 0.2;
     root["fighter"]["normal"]["longSight"] = 70;
     root["fighter"]["normal"]["shortSight"] = 60;
     root["fighter"]["weapon"]["radius"] = 2;
     root["fighter"]["weapon"]["speed"] = 20;
     root["fighter"]["weapon"]["damage"] = 20;
     root["fighter"]["weapon"]["cd"] = 10;
     root["fighter"]["rebuild"]["tick"] = 200;
     root["fighter"]["rebuild"]["power"] = 100;
     root["littleStar"]["power"] = 40;
     root["littleStar"]["radius"] = 5;
     root["littleStar"]["collectTick"] = 20;
     root["largeStar"]["power"] = 20;
     root["largeStar"]["radius"] = 3;
     root["largeStar"]["collectTick"] = 10;
}

void Configuration::writeToYaml(){
    log->information("写入配置项到文件");
    ofstream out(file);
    out << YAML::Dump(root);
}

YAML::Node Configuration::getRoot() const{
    return root;
}

shared_ptr<GameConfiguration> Configuration::getGameConfiguration() const{
    return gameConfig;
}
