// Copyright (c) 2014-2024, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#include <string>

#include "gtest/gtest.h"

#include "crypto/twofish.h"

namespace
{
  struct test_data {
    const uint8_t* key;
    const uint8_t* iv;
    const size_t plain_text_length;
    const uint8_t* plain_text;
    const size_t cipher_text_length;
    const uint8_t* cipher_text;
  };

  #define ARR(...) __VA_ARGS__

  #define MAKE_TEST_DATA(index, key, iv, plain_text, cipher_text)  \
    static const uint8_t test_key_##index[]         = key;         \
    static const uint8_t test_iv_##index[]          = iv;          \
    static const uint8_t test_plain_text_##index[]  = plain_text;  \
    static const uint8_t test_cipher_text_##index[] = cipher_text; \
    static const test_data test_##index = {test_key_##index, test_iv_##index, sizeof(test_plain_text_##index), test_plain_text_##index, sizeof(test_cipher_text_##index), test_cipher_text_##index};

  MAKE_TEST_DATA(
    0,
    ARR({0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x8f, 0xae, 0x71, 0x3f, 0x67, 0x7a, 0x82, 0x07, 0x5d, 0x77, 0x3d, 0xb7, 0x3d, 0x58, 0x76, 0x3e, 0x7b, 0x95, 0x7c, 0x23, 0x63, 0xb4, 0x57, 0x82, 0xbb, 0x97, 0xf8, 0xd2, 0x83, 0x7e, 0x2b, 0x56, 0x7b, 0xcc, 0xf4, 0xc6, 0xd7, 0xad, 0x78, 0xe3, 0x8f, 0x33, 0x44, 0xc0, 0x4f, 0x67, 0x2e, 0x1a, 0xd7, 0x0a, 0x6c, 0x2d, 0xaa, 0xd6, 0x82, 0xf7, 0x8b, 0xc0, 0xaa, 0xa9, 0x73, 0xc0, 0xae, 0x68, 0xaa, 0xd9, 0xf4, 0x17, 0x9f, 0xdb, 0xcb, 0xfc, 0xc0, 0x65, 0xa8, 0xb9, 0xcf, 0xb3, 0x76, 0xb8})
  )

  MAKE_TEST_DATA(
    1,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9, 0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x8f, 0x2e, 0xee, 0xe4, 0x3e, 0x0f, 0x06, 0xe2, 0xff, 0x4d, 0x24, 0x98, 0xa7, 0x4f, 0xdd, 0x40, 0xe4, 0xc2, 0x11, 0x34, 0x15, 0x5e, 0xe2, 0x7e, 0x4d, 0x6f, 0x49, 0x86, 0x5a, 0x76, 0x08, 0x8a, 0x12, 0x39, 0xe3, 0x1b, 0x96, 0x10, 0x80, 0x1c, 0xf7, 0x73, 0x4a, 0x2c, 0x0c, 0x7c, 0x37, 0xd0, 0x3c, 0x70, 0xde, 0x63, 0x3d, 0xcd, 0x72, 0x6b, 0x89, 0xd4, 0x86, 0xab, 0x46, 0x49, 0xfd, 0x9f, 0x3c, 0x31, 0x65, 0x0a, 0xc4, 0x66, 0x82, 0x9c, 0xf5, 0xe3, 0x58, 0x36, 0x68, 0xba, 0x1e, 0x7a})
  )

  MAKE_TEST_DATA(
    2,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9, 0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}),
    ARR({0x8f, 0x2e, 0xee, 0xe4, 0x3e, 0x0f, 0x06, 0xe2, 0xff, 0x4d, 0x24, 0x98, 0xa7, 0x4f, 0xdd, 0x40, 0xe4, 0xc2, 0x11, 0x34, 0x15, 0x5e, 0xe2, 0x7e, 0x4d, 0x6f, 0x49, 0x86, 0x5a, 0x76, 0x08, 0x8a, 0x12, 0x39, 0xe3, 0x1b, 0x96, 0x10, 0x80, 0x1c, 0xf7, 0x73, 0x4a, 0x2c, 0x0c, 0x7c, 0x37, 0xd0, 0x3c, 0x70, 0xde, 0x63, 0x3d, 0xcd, 0x72, 0x6b, 0x89, 0xd4, 0x86, 0xab, 0x46, 0x49, 0xfd, 0x9f, 0x18, 0x4e, 0xfb, 0xae, 0xbd, 0x71, 0x38, 0x76, 0x62, 0x9c, 0xc2, 0x03, 0x31, 0x0d, 0x01, 0x0f})
  )

  MAKE_TEST_DATA(
    3,
    ARR({0x0f, 0x62, 0xb5, 0x08, 0x5b, 0xae, 0x01, 0x54, 0xa7, 0xfa, 0x4d, 0xa0, 0xf3, 0x46, 0x99, 0xec, 0x3f, 0x92, 0xe5, 0x38, 0x8b, 0xde, 0x31, 0x84, 0xd7, 0x2a, 0x7d, 0xd0, 0x23, 0x76, 0xc9, 0x1c}),
    ARR({0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9, 0x28, 0x8f, 0xf6, 0x5d, 0xc4, 0x2b, 0x92, 0xf9}),
    ARR({0x00}),
    ARR({0x35, 0xc8, 0xfa, 0x6f, 0x79, 0x22, 0x98, 0x55, 0x98, 0x51, 0xb3, 0x68, 0xba, 0x4a, 0xf2, 0x95})
  )

  void run_test(const test_data* test)
  {
    std::string buf;
    buf.resize(crypto::twofish_encrypted_size(test->plain_text_length));
    ASSERT_EQ(buf.size(), test->cipher_text_length);

    crypto::twofish_encrypt(test->plain_text, test->plain_text_length, test->key, test->iv, &buf[0]);
    ASSERT_EQ(buf, std::string(reinterpret_cast<const char*>(test->cipher_text), test->cipher_text_length));

    buf.resize(crypto::twofish_decrypt(test->cipher_text, test->cipher_text_length, test->key, test->iv, &buf[0]));
    ASSERT_EQ(buf.size(), test->plain_text_length);
    ASSERT_EQ(buf, std::string(reinterpret_cast<const char*>(test->plain_text), test->plain_text_length));
  }
}

#define TEST_TWOFISH(test_no)          \
  TEST(twofish, is_correct_##test_no)  \
  {                                    \
    run_test(&test_##test_no);         \
  }

TEST_TWOFISH(0)
TEST_TWOFISH(1)
TEST_TWOFISH(2)
TEST_TWOFISH(3)
