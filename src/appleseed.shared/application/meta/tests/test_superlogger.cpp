
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010-2011 Francois Beaune
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

// appleseed.shared headers.
#include "application/superlogger.h"

// appleseed.foundation headers.
#include "foundation/utility/log.h"
#include "foundation/utility/test.h"

using namespace appleseed::shared;
using namespace foundation;

TEST_SUITE(Application_SuperLogger)
{
    TEST_CASE(Constructor_SetsLogTargetFormattingFlagsToCategoryAndMessage)
    {
        SuperLogger super_logger;

        const LogMessage::FormattingFlags flags =
            super_logger.get_log_target().get_formatting_flags(LogMessage::Info);

        EXPECT_EQ(LogMessage::DisplayCategory | LogMessage::DisplayMessage, flags);
    }

    TEST_CASE(EnableMessageColoring_PreservesLogTargetFlags)
    {
        SuperLogger super_logger;

        super_logger.get_log_target().set_formatting_flags(
            LogMessage::Info,
            static_cast<LogMessage::FormattingFlags>(
                LogMessage::DisplayDate | LogMessage::DisplayTime));

        super_logger.enable_message_coloring();

        const LogMessage::FormattingFlags flags =
            super_logger.get_log_target().get_formatting_flags(LogMessage::Info);

        EXPECT_EQ(LogMessage::DisplayDate | LogMessage::DisplayTime, flags);
    }
}