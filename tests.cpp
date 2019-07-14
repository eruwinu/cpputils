#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <string>

#include "index.hpp"

using namespace testing;

class UtilShould : public Test
{
protected:
    Util sut_;
};

TEST_F(UtilShould, Chunk)
{
    std::vector<Set> sets{
        Set{0, 0.0, "zero"},
        Set{1, 1.0, "one"},
        Set{2, 2.0, "two"},
        Set{3, 3.0, "three"},
        Set{4, 4.0, "four"},
        Set{5, 5.0, "five"},
        Set{6, 6.0, "six"},
        Set{7, 7.0, "seven"},
        Set{8, 8.0, "eight"},
        Set{9, 9.0, "nine"},
        Set{10, 10.0, "ten"},
        Set{11, 11.0, "eleven"},
    };
    ASSERT_THAT(sut_.chunk(2, sets),
        ElementsAre(
            ElementsAre(
                std::ref(sets.at(0)),
                std::ref(sets.at(1))
            ),
            ElementsAre(
                std::ref(sets.at(2)),
                std::ref(sets.at(3))
            ),
            ElementsAre(
                std::ref(sets.at(4)),
                std::ref(sets.at(5))
            ),
            ElementsAre(
                std::ref(sets.at(6)),
                std::ref(sets.at(7))
            ),
            ElementsAre(
                std::ref(sets.at(8)),
                std::ref(sets.at(9))
            ),
            ElementsAre(
                std::ref(sets.at(10)),
                std::ref(sets.at(11))
            )
        ));
    ASSERT_THAT(sut_.chunk(3, sets),
        ElementsAre(
            ElementsAre(
                std::ref(sets.at(0)),
                std::ref(sets.at(1)),
                std::ref(sets.at(2))
            ),
            ElementsAre(
                std::ref(sets.at(3)),
                std::ref(sets.at(4)),
                std::ref(sets.at(5))
            ),
            ElementsAre(
                std::ref(sets.at(6)),
                std::ref(sets.at(7)),
                std::ref(sets.at(8))
            ),
            ElementsAre(
                std::ref(sets.at(9)),
                std::ref(sets.at(10)),
                std::ref(sets.at(11))
            )
        ));
    ASSERT_THAT(sut_.chunk(4, sets),
        ElementsAre(
            ElementsAre(
                std::ref(sets.at(0)),
                std::ref(sets.at(1)),
                std::ref(sets.at(2)),
                std::ref(sets.at(3))
            ),
            ElementsAre(
                std::ref(sets.at(4)),
                std::ref(sets.at(5)),
                std::ref(sets.at(6)),
                std::ref(sets.at(7))
            ),
            ElementsAre(
                std::ref(sets.at(8)),
                std::ref(sets.at(9)),
                std::ref(sets.at(10)),
                std::ref(sets.at(11))
            )
        ));
    ASSERT_THAT(sut_.chunk(5, sets),
        ElementsAre(
            ElementsAre(
                std::ref(sets.at(0)),
                std::ref(sets.at(1)),
                std::ref(sets.at(2)),
                std::ref(sets.at(3)),
                std::ref(sets.at(4))
            ),
            ElementsAre(
                std::ref(sets.at(5)),
                std::ref(sets.at(6)),
                std::ref(sets.at(7)),
                std::ref(sets.at(8)),
                std::ref(sets.at(9))
            ),
            ElementsAre(
                std::ref(sets.at(10)),
                std::ref(sets.at(11))
            )
        ));
}

TEST_F(UtilShould, GroupBy)
{
    std::vector<Set> sets{
        Set{0, 0.0, "zero"},
        Set{1, 1.0, "one"},
        Set{2, 2.0, "two"},
        Set{3, 3.0, "three"},
        Set{4, 4.0, "four"},
        Set{5, 5.0, "five"},
        Set{6, 6.0, "six"},
        Set{7, 7.0, "seven"},
        Set{8, 8.0, "eight"},
        Set{9, 9.0, "nine"},
        Set{10, 10.0, "ten"},
        Set{11, 11.0, "eleven"},
    };   
}

TEST_F(UtilShould, FlatMap)
{
}