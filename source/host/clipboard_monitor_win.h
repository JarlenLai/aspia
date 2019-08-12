//
// Aspia Project
// Copyright (C) 2019 Dmitry Chapyshev <dmitry@aspia.ru>
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

#ifndef HOST__CLIPBOARD_MONITOR_WIN_H
#define HOST__CLIPBOARD_MONITOR_WIN_H

#include "host/clipboard_monitor.h"

namespace host {

class ClipboardMonitorWin : public ClipboardMonitor
{
public:
    ~ClipboardMonitorWin() = default;

    // ClipboardMonitor implementation.
    void injectClipboardEvent(const proto::ClipboardEvent& event) override;
};

} // namespace host

#endif // HOST__CLIPBOARD_MONITOR_WIN_H
