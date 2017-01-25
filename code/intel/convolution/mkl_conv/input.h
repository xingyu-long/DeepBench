/*******************************************************************************
* Copyright 2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include <vector>

struct conv_problem {
    int groups;
    int minibatch;
    int w;
    int h;
    int ic;
    int oc;
    int fw;
    int fh;
    int stride;
    int padd;
    int iters;
    const char *name;
};

static const std::vector<conv_problem> conv_problems = {
    // Use libxsmm for the non-square convolutions
    // {1, 4, 700, 161, 1, 32, 5, 20, 2, 0, 1000, ""},
    // {1, 8, 700, 161, 1, 32, 5, 20, 2, 0, 1000, ""},
    // {1, 16, 700, 161, 1, 32, 5, 20, 2, 0, 1000, ""},
    // {1, 32, 700, 161, 1, 32, 5, 20, 2, 0, 1000, ""},
    // {1, 4, 341, 79, 32, 32, 5, 10, 2, 0, 1000, ""},
    // {1, 8, 341, 79, 32, 32, 5, 10, 2, 0, 1000, ""},
    // {1, 16, 341, 79, 32, 32, 5, 10, 2, 0, 1000, ""},
    // {1, 32, 341, 79, 32, 32, 5, 10, 2, 0, 1000, ""},
    {1, 16, 480, 48, 1, 16, 3, 3, 1, 1, 1000, ""},
    {1, 16, 240, 24, 16, 32, 3, 3, 1, 1, 1000, ""},
    {1, 16, 120, 12, 32, 64, 3, 3, 1, 1, 1000, ""},
    {1, 16, 60, 6, 64, 128, 3, 3, 1, 1, 1000, ""},
    {1, 8, 108, 108, 3, 64, 3, 3, 2, 1, 1000, ""},
    {1, 8, 54, 54, 64, 64, 3, 3, 1, 1, 1000, ""},
    {1, 8, 27, 27, 128, 128, 3, 3, 1, 1, 1000, ""},
    {1, 8, 14, 14, 128, 256, 3, 3, 1, 1, 1000, ""},
    {1, 8, 7, 7, 256, 512, 3, 3, 1, 1, 1000, ""},
    {1, 8, 224, 224, 3, 64, 3, 3, 1, 1, 1000, ""},
    {1, 8, 112, 112, 64, 128, 3, 3, 1, 1, 1000, ""},
    {1, 8, 56, 56, 128, 256, 3, 3, 1, 1, 1000, ""},
    {1, 8, 28, 28, 256, 512, 3, 3, 1, 1, 1000, ""},
    {1, 8, 14, 14, 512, 512, 3, 3, 1, 1, 1000, ""},
    {1, 8, 7, 7, 512, 512, 3, 3, 1, 1, 1000, ""},
    {1, 16, 224, 224, 3, 64, 3, 3, 1, 1, 1000, ""},
    {1, 16, 112, 112, 64, 128, 3, 3, 1, 1, 1000, ""},
    {1, 16, 56, 56, 128, 256, 3, 3, 1, 1, 1000, ""},
    {1, 16, 28, 28, 256, 512, 3, 3, 1, 1, 1000, ""},
    {1, 16, 14, 14, 512, 512, 3, 3, 1, 1, 1000, ""},
    {1, 16, 7, 7, 512, 512, 3, 3, 1, 1, 1000, ""},
    {1, 16, 224, 224, 3, 64, 7, 7, 2, 3, 1000, ""},
    {1, 16, 28, 28, 192, 32, 5, 5, 1, 2, 1000, ""},
    {1, 16, 28, 28, 192, 64, 1, 1, 1, 0, 1000, ""},
    {1, 16, 14, 14, 512, 48, 5, 5, 1, 2, 1000, ""},
    {1, 16, 14, 14, 512, 192, 1, 1, 1, 0, 1000, ""},
    {1, 16, 7, 7, 832, 256, 1, 1, 1, 0, 1000, ""},
    {1, 16, 7, 7, 832, 128, 5, 5, 1, 2, 1000, ""},
};
