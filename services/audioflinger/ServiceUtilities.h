/*
 * Copyright (C) 2012 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cutils/multiuser.h>
#include <private/android_filesystem_config.h>
#include <unistd.h>

#include <binder/PermissionController.h>

namespace android {

// Used for calls that should originate from system services.
// We allow that some services might have separate processes to
// handle multiple users, e.g. u10_system, u10_bluetooth, u10_radio.
static inline bool isServiceUid(uid_t uid) {
    return multiuser_get_app_id(uid) < AID_APP_START;
}

extern pid_t getpid_cached;
bool isTrustedCallingUid(uid_t uid);
bool recordingAllowed(const String16& opPackageName, pid_t pid, uid_t uid);
bool startRecording(const String16& opPackageName, pid_t pid, uid_t uid);
void finishRecording(const String16& opPackageName, uid_t uid);
bool captureAudioOutputAllowed(pid_t pid, uid_t uid);
bool captureHotwordAllowed(pid_t pid, uid_t uid);
bool settingsAllowed();
bool modifyAudioRoutingAllowed();
bool dumpAllowed();
bool modifyPhoneStateAllowed(pid_t pid, uid_t uid);
}
