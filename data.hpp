/*
 * Copyright (C) 2007 The Android Open Source Project
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

#ifndef _DATAMANAGER_HPP_HEADER
#define _DATAMANAGER_HPP_HEADER

#include <string>
#include <utility>
#include <map>

using namespace std;

class DataManager
{
public:
    static int ResetDefaults();
    static int LoadValues(const string filename);

    // Core get routines
    static int GetValue(const string varName, string& value);
    static int GetValue(const string varName, int& value);

    // This is a dangerous function. It will create the value if it doesn't exist so it has a valid c_str
    static string& GetValueRef(const string varName);

    // Helper functions
    static string GetStrValue(const string varName);
    static int GetIntValue(const string varName);

    // Core set routines
    static int SetValue(const string varName, string value, int persist = 0);
    static int SetValue(const string varName, int value, int persist = 0);
    static int SetValue(const string varName, float value, int persist = 0);

    static void DumpValues();

    // Magic Values
    static int GetMagicValue(const string varName, string& value);

protected:
    typedef pair<string, int> TStrIntPair;
    typedef pair<string, TStrIntPair> TNameValuePair;
    static map<string, TStrIntPair> mValues;
    static string mBackingFile;
    static int mInitialized;

    static map<string, string> mConstValues;

protected:
    static int SaveValues();
    static void SetDefaultValues();

    static int GetMagicValue(string varName, string& value);

};

#endif _DATAMANAGER_HPP_HEADER

