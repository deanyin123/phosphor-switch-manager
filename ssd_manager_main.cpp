#include <sdbusplus/bus.hpp>
#include "config.h"
#include "ssd_manager.hpp"
#include <string>
#include <iostream>

int main(int argc, char**)
{
    auto SSDName = "ssd";
    auto SSDNum = 12; //get from i2c -c ssdinfo
    std::string objPathlist[24];

    for(int i = 0; i < SSDNum; i++)
    {
        objPathlist[i] = std::string(SSD_OBJPATH) + '/' + SSDName;
        auto char_i = std::to_string(i+1);
        objPathlist[i] += char_i;
    }

    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    sdbusplus::server::manager::manager objManager(bus, SSD_OBJPATH);
    
    std::vector<std::unique_ptr<phosphor::ssd::manager::SSD>> ssds;

    auto ssdtype = "U.2";
    for (auto& ssdpath : objPathlist)
    {
        if(ssdpath.empty())
            break;
        ssds.emplace_back(
            std::make_unique<phosphor::ssd::manager::SSD>(bus, ssdpath, ssdtype));
    }
    
    bus.request_name(SSD_BUSNAME);

    while (true)
    {
        bus.process_discard();
        bus.wait();
    }

    return 0;
}
