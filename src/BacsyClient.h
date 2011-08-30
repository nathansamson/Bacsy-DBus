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

#ifndef _BACSY_CLIENT_H_
#define _BACSY_CLIENT_H_

#include <dbus-c++/dbus.h>

#include "bacsy-glue.h"

namespace BacsyDBus
{
	static const std::string BACSY_CLIENT_PATH = "/org/bacsy/Client";

	class BacsyClient
		: public org::bacsy::Client_adaptor,
		  public DBus::IntrospectableAdaptor,
		  public DBus::ObjectAdaptor
	{
	public:
		BacsyClient(DBus::Connection &connection);
	
		std::vector<std::string> Sources();
	};
}

#endif
