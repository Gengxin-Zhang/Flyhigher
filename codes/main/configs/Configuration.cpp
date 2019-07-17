/**
 * Project FLyhigher
 * @author Untitled
 * @version v1.0 beta
 */


#include "Configuration.h"
#include "../systems/Engine.h"
#include <string>
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
        config = shared_ptr<Configuration>(new Configuration("./config.yml"));
        isInit = true;
    }
    return config;
}

void Configuration::reload() {
    bool defaultMode = false;
    root = YAML::Load(file);
    if (root.IsNull()){
        log->warning("读取config失败，YAML为空！");
        defaultMode = true;
    }
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
    int height = 500, width = 500, maxAllowPlayer = 2;
    Point2D ps[2] = {Point2D(75, 75), Point2D(425, 425)};
    if(!defaultMode){
        height = root["map"]["height"].as<int>();
        width = root["map"]["width"].as<int>();
        int maxAllowPlayer = root["map"]["maxAllowPlayer"].as<int>();
        for(int i=1; i<=maxAllowPlayer; ++i){
            double x = root["map"]["birthPlaces"][to_string(i)]["x"].as<double>();
            double y = root["map"]["birthPlaces"][to_string(i)]["y"].as<double>();
            ps[i-1] = Point2D(x, y);
        }
    }
    shared_ptr<MapConfiguration> mapConfig =
            shared_ptr<MapConfiguration>(new MapConfiguration(height, width, maxAllowPlayer, ps));
    int health = 2000, healRate = 0, healPower = 0;
    double speed = 0.1, radius = 30;
    if(!defaultMode){
        health = root["carrier"]["normal"]["health"].as<int>();
        speed = root["carrier"]["normal"]["speed"].as<double>();
        radius = root["carrier"]["normal"]["radius"].as<double>();
        healRate = root["carrier"]["normal"]["healRate"].as<int>();
        healPower = root["carrier"]["normal"]["healPower"].as<int>();
    }
    double weapon_radius = 10, bullet_speed = 5;
    int damage = 60, delay = 100;
    if(!defaultMode){
        weapon_radius = root["carrier"]["weapon"]["radius"].as<double>();
        bullet_speed = root["carrier"]["weapon"]["speed"].as<double>();
        damage = root["carrier"]["weapon"]["damage"].as<int>();
        delay = root["carrier"]["weapon"]["cd"].as<int>();
    }
    int aoeDamage = 2000, damageDecrease=20;
    double aoeRadius = 100, nuke_radius = 50, nuke_speed = 5;
    if(!defaultMode){
        aoeDamage = root["carrier"]["nuke"]["aoeDamage"].as<int>();
        aoeRadius = root["carrier"]["nuke"]["aoeRadius"].as<double>();
        damageDecrease = root["carrier"]["nuke"]["damageDecrease"].as<int>();
        nuke_radius = root["carrier"]["nuke"]["radius"].as<double>();
        nuke_speed = root["carrier"]["nuke"]["speed"].as<double>();
    }
    double sightAngle = 0.6, longSight = 100, shortSight = 50;
    if(!defaultMode){
        sightAngle = root["carrier"]["normal"]["sightAngle"].as<double>();
        longSight = root["carrier"]["normal"]["longSight"].as<double>();
        shortSight  = root["carrier"]["normal"]["shortSight"].as<double>();
    }
    shared_ptr<CarrierConfiguration> carrierConfig =
            shared_ptr<CarrierConfiguration>(new CarrierConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(weapon_radius, damage, bullet_speed, delay)),
                shared_ptr<NukeConfiguration>(new NukeConfiguration(aoeDamage, aoeRadius, damageDecrease, nuke_radius, nuke_speed)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(health, speed, radius, healRate, healPower, sightAngle, longSight, shortSight))));
    int b_health = 500, b_healRate = 1, b_healPower = 20;
    double b_speed = 0.5, b_radius = 10;
    if(!defaultMode){
        b_health = root["bomber"]["normal"]["health"].as<int>();
        b_speed = root["bomber"]["normal"]["speed"].as<double>();
        b_radius = root["bomber"]["normal"]["radius"].as<double>();
        b_healRate = root["bomber"]["normal"]["healRate"].as<int>();
        b_healPower = root["bomber"]["normal"]["healPower"].as<int>();
    }
    double b_weapon_radius = 10, b_bullet_speed = 10;
    int b_damage = 80, b_delay = 50;
    if(!defaultMode){
        b_weapon_radius = root["bomber"]["weapon"]["radius"].as<double>();
        b_bullet_speed = root["bomber"]["weapon"]["speed"].as<double>();
        b_damage = root["bomber"]["weapon"]["damage"].as<int>();
        b_delay = root["bomber"]["weapon"]["cd"].as<int>();
    }
    double b_sightAngle = 0.4, b_longSight = 80, b_shortSight = 40;
    if(!defaultMode){
        b_sightAngle = root["bomber"]["normal"]["sightAngle"].as<double>();
        b_longSight = root["bomber"]["normal"]["longSight"].as<double>();
        b_shortSight  = root["bomber"]["normal"]["shortSight"].as<double>();
    }
    shared_ptr<BomberConfiguration> bomberConfig =
            shared_ptr<BomberConfiguration>(new BomberConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(b_weapon_radius, b_damage, b_bullet_speed, b_delay)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(b_health, b_speed, b_radius, b_healRate, b_healPower, b_sightAngle, b_longSight, b_shortSight))));
    int f_health = 200, f_healRate = 5, f_healPower = 5;
    double f_speed = 5, f_radius = 10;
    if(!defaultMode){
        f_health = root["fighter"]["normal"]["health"].as<int>();
        f_speed = root["fighter"]["normal"]["speed"].as<double>();
        f_radius = root["fighter"]["normal"]["radius"].as<double>();
        f_healRate = root["fighter"]["normal"]["healRate"].as<int>();
        f_healPower = root["fighter"]["normal"]["healPower"].as<int>();
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
    double f_sightAngle = 0.2, f_longSight = 40, f_shortSight = 20;
    if(!defaultMode){
        f_sightAngle = root["bomber"]["normal"]["sightAngle"].as<double>();
        f_longSight = root["bomber"]["normal"]["longSight"].as<double>();
        f_shortSight  = root["bomber"]["normal"]["shortSight"].as<double>();
    }
    shared_ptr<FighterConfiguration> fighterConfig =
            shared_ptr<FighterConfiguration>(new FighterConfiguration(
                shared_ptr<WeaponConfiguration>(new WeaponConfiguration(f_weapon_radius, f_damage, f_bullet_speed, f_delay)),
                shared_ptr<RebuildableConfiguration>(new RebuildableConfiguration(rebuild_power, rebuild_tick)),
                shared_ptr<PlaneConfiguration>(new PlaneConfiguration(f_health, f_radius, f_speed, f_healRate, f_healPower, f_sightAngle, f_longSight, f_shortSight))));
    shared_ptr<PlayerConfiguration> playerConfig = shared_ptr<PlayerConfiguration>(new PlayerConfiguration(carrierConfig, bomberConfig, fighterConfig));
    int little_power = 20, little_radius = 3, little_collectTick = 10;
    if(!defaultMode){
        little_power = root["littleStar"]["power"].as<int>();
        little_radius = root["littleStar"]["radius"].as<int>();
        little_collectTick = root["littleStar"]["collectTick"].as<int>();
    }
    shared_ptr<LittleStarConfiguration> littleConfig = shared_ptr<LittleStarConfiguration>(new LittleStarConfiguration(little_power, little_radius, little_collectTick));
    int large_power = 40, large_radius = 5, large_collectTick = 20;
    if(!defaultMode){
        little_power = root["largeStar"]["power"].as<int>();
        little_radius = root["largeStar"]["radius"].as<int>();
        little_collectTick = root["largeStar"]["collectTick"].as<int>();
    }
    shared_ptr<LargeStarConfiguration> largeConfig = shared_ptr<LargeStarConfiguration>(new LargeStarConfiguration(large_power, large_radius, large_collectTick));
    this->gameConfig = shared_ptr<GameConfiguration>(new GameConfiguration(mapConfig, judgerConfig, loopConfig, playerNumber, playerConfig, largeConfig, littleConfig));
}

shared_ptr<GameConfiguration> Configuration::getGameConfiguration() const{
    return gameConfig;
}
