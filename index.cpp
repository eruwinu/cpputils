#include <algorithm>

#include "index.hpp"

Util::Util()
{
}

Util::~Util()
{
}

template<typename T>
std::vector<std::vector<std::reference_wrapper<T const>>> Util::chunk(size_t chunkSize, std::vector<T> items) const
{
    using Chunk = std::vector<std::reference_wrapper<T const>>;
    using Chunks = std::vector<Chunk>;

    Chunks chunks{};
    for (auto const& item : items)
    {
        if (chunks.size() == 0 or chunks.back().size() == chunkSize)
            chunks.emplace_back(Chunk{});

        chunks.back().emplace_back(std::cref(item));
    }

    return chunks;
}

template std::vector<std::vector<std::reference_wrapper<Set const>>> Util::chunk(size_t, std::vector<Set> items) const;