AM_DEFAULT_SOURCE_EXT = .cpp

sbin_PROGRAMS = phosphor-ssd-manager

phosphor_ssd_manager_SOURCES = \
	ssd_manager_main.cpp 
    
    
phosphor_ssd_manager_LDFLAGS = $(SDBUSPLUS_LIBS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_LIBS)
phosphor_ssd_manager_CFLAGS =  $(SDBUSPLUS_CFLAGS) \
                                 $(PHOSPHOR_DBUS_INTERFACES_CFLAGS)


