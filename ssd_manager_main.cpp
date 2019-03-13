#include <sdbusplus/bus.hpp>
#include "config.h"
#include "ssd_manager.hpp"

int main(int argc, char**)
{
    auto objPath = std::string(SSD_OBJPATH) + '/' + 'ssd0';
    
    auto bus = sdbusplus::bus::new_default();

    // Add sdbusplus ObjectManager.
    //sdbusplus::server::manager::manager objManager(bus, objPath.c_str);
    sdbusplus::server::manager::manager objManager(bus, SSD_OBJPATH);
    
    phosphor::ssd::manager::SSD manager(bus, objPath.c_str()) 

    bus.request_name(SSD_BUSNAME);

    while (true)
    {
        bus.process_discard();
        bus.wait();
    }

    return 0;
}
