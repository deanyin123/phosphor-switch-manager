#pragma once

#include <functional>
#include <sdbusplus/bus.hpp>
#include <xyz/openbmc_project/Switch/Ssd/server.hpp>
#include <sdbusplus/server/object.hpp>

namespace phosphor
{
namespace ssd
{
namespace manager
{

using SSDInherit = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::Switch::server::Ssd>;

/** @class BMC
 *  @brief OpenBMC BMC state management implementation.
 *  @details A concrete implementation for xyz.openbmc_project.State.BMC
 *  DBus API.
 */
class SSDInit: public SSDInherit
{
  public:
    /** @brief Constructs SSD  Manager
     *
     * @param[in] bus       - The Dbus bus object
     * @param[in] busName   - The Dbus name to own
     * @param[in] objPath   - The Dbus object path
     */
    SSDInit() = delete;
    ~SSDInit() = default;
    SSDInit(const SSDInit&) = delete;
    SSDInit& operator=(const SSDInit&) = delete;
    SSDInit(SSDInit&&) = delete;
    SSDInit& operator=(SSDInit&&) = delete;
    
    SSDInit(sdbusplus::bus::bus& bus, const std::string& objPath, const std::string& ssdtype):
        SSDInherit(bus, objPath.c_str(), true), path(objPath)
    {
        type(ssdtype);
        emit_object_added();
    }
    
  private:
    std::string path;
};

class SSDInfo
{
    public:
        int get_ssdnum(void);
    
};

} // namespace manager
} // namespace ssd
} // namespace phosphor
