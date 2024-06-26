/*
 * SPDX-License-Identifier: GPL-3.0-only
 * MuseScore-CLA-applies
 *
 * MuseScore
 * Music Composition & Notation
 *
 * Copyright (C) 2021 MuseScore BVBA and others
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef AU_AU3WRAP_PROJECTMODULE_H
#define AU_AU3WRAP_PROJECTMODULE_H

#include "modularity/imodulesetup.h"

namespace au::au3 {
class WxLogWrap;
class Au3Playback;
class Au3Record;
class Au3AudioDevicesManager;
class Au3WrapModule : public muse::modularity::IModuleSetup
{
public:

    std::string moduleName() const override;
    void registerExports() override;
    void onInit(const muse::IApplication::RunMode& mode) override;
    void onDeinit() override;

private:

    WxLogWrap* m_wxLog = nullptr;

    std::shared_ptr<Au3Playback> m_playback;
    std::shared_ptr<Au3Record> m_record;
    std::shared_ptr<Au3AudioDevicesManager> m_audioDevicesManager;
};
}

#endif // AU_AU3WRAP_PROJECTMODULE_H
