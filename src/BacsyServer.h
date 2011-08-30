/*
    This file is part of Bacsy-DBus.

    Bacsy-DBus is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Bacsy-DBus is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Bacsy-DBus.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _BACSY_SERVER_H_
#define _BACSY_SERVER_H_

#include <dbus-c++/dbus.h>

#include <bacsy/BacsyServer.h>
#include <bacsy/MulticastResponder.h>
#include <bacsy/StoreManager.h>

#include "bacsy-glue.h"

namespace BacsyDBus
{
	static const std::string BACSY_SERVER_PATH = "/org/bacsy/Server";

	class BacsyServer
		: public org::bacsy::Server_adaptor,
		  public DBus::IntrospectableAdaptor,
		  public DBus::ObjectAdaptor
	{
	public:
		BacsyServer(DBus::Connection &connection);
	
		std::vector<std::string> Stores();
	private:
		::CascadingFileConfiguration configuration;
		::StoreManager storeManager;
		::BacsyServer server;
		::MulticastResponder responder;
	};
}

#endif
