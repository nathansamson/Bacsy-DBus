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

#include <iostream>
#include <signal.h>

#include <dbus-c++/dbus.h>

#include "BacsyClient.h"
#include "BacsyServer.h"

DBus::BusDispatcher dispatcher;

static const std::string BACSY_NAME= "org.bacsy";

void niam(int sig)
{
	dispatcher.leave();
}

int main(int argc, char** argv)
{
	signal(SIGTERM, niam);
	signal(SIGINT, niam);

	DBus::default_dispatcher = &dispatcher;

	DBus::Connection connection = DBus::Connection::SessionBus();
	connection.request_name(BACSY_NAME.c_str());

	BacsyDBus::BacsyClient bacsy_client(connection);
	BacsyDBus::BacsyServer bacsy_server(connection);

	dispatcher.enter();
	return 0;
}
