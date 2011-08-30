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

#include <bacsy/Environment.h>

#include "BacsyServer.h"

namespace BacsyDBus
{
	BacsyServer::BacsyServer(DBus::Connection& connection)
		: DBus::ObjectAdaptor(connection, BACSY_SERVER_PATH),
		  configuration(Environment::getDefaultConfigurationDirectory()),
		  storeManager(configuration),
		  server(storeManager),
		  responder()
	{
		server.start();
		responder.start();
	}

	std::vector<std::string> BacsyServer::Stores()
	{
		return std::vector<std::string>();
	}
}
