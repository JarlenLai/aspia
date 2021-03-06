//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "router/session.h"

#include "base/logging.h"
#include "net/channel.h"
#include "router/database_sqlite.h"

namespace router {

Session::Session(std::unique_ptr<net::Channel> channel)
    : channel_(std::move(channel))
{
    DCHECK(channel_);
}

Session::~Session() = default;

void Session::start(Delegate* delegate)
{
    delegate_ = delegate;
    DCHECK(delegate_);

    channel_->setListener(this);
    channel_->resume();
}

bool Session::isFinished() const
{
    return channel_ == nullptr;
}

void Session::setVersion(const base::Version& version)
{
    version_ = version;
}

void Session::setUserName(const std::u16string& username)
{
    username_ = username;
}

void Session::send(base::ByteArray&& buffer)
{
    if (channel_)
        channel_->send(std::move(buffer));
}

void Session::onConnected()
{
    NOTREACHED();
}

void Session::onDisconnected(net::Channel::ErrorCode error_code)
{
    LOG(LS_INFO) << "Network error: " << net::Channel::errorToString(error_code);

    if (delegate_)
        delegate_->onSessionFinished();
}

} // namespace router
