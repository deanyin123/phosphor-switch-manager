#pragma once

#include <functional>
#include <sdbusplus/bus.hpp>
#include "xyz/openbmc_project/switch/Ssd/server.hpp"

namespace phosphor
{
namespace ssd
{
namespace manager
{

using SSDInherit = sdbusplus::server::object::object<
    sdbusplus::xyz::openbmc_project::switch::server::Ssd>;
namespace sdbusRule = sdbusplus::bus::match::rules;

/** @class BMC
 *  @brief OpenBMC BMC state management implementation.
 *  @details A concrete implementation for xyz.openbmc_project.State.BMC
 *  DBus API.
 */
class SSD : public SSDInherit
{
  public:
    /** @brief Constructs SSD  Manager
     *
     * @param[in] bus       - The Dbus bus object
     * @param[in] busName   - The Dbus name to own
     * @param[in] objPath   - The Dbus object path
     */
    SSD(sdbusplus::bus::bus& bus, const char* objPath) :
        SSDInherit(bus, objPath, true), bus(bus)
    {
        //
    };

  private:
    sdbusplus::bus::bus& bus;
};

} // namespace manager
} // namespace state
} // namespace phosphor
