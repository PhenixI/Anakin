/* Copyright (c) 2018 Baidu, Inc. All Rights Reserved.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0
   
   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License. 
*/

#ifndef ANAKIN_TLS_H
#define ANAKIN_TLS_H 

#include "framework/core/common_macros.h"

namespace anakin {

template<typename T>
class AnakinThreadLocalVar {
public:
    static T* value() {
        if (!_instance) {
            _instance = new T();
            return _instance; 
        }
        return _instance;
    }
private:
    AnakinThreadLocalVar() = default;
    ~AnakinThreadLocalVar() = default;
    AK_THREAD_LOCAL static T* _instance;
};

template<typename T>
AK_THREAD_LOCAL T* AnakinThreadLocalVar<T>::_instance = nullptr;

} /* namespace anakin */

#endif
