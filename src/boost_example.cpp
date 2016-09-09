/*
 * boost_example.cpp
 * Copyright (C) 2016 lisanmiao <lisanmiao@cp01-rdqa-dev367.cp01.baidu.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>

int main() {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
            in(std::cin), in(), std::cout << (_1 * 3) << " " );
}



