
#include "PMergeMe.hpp"

static std::vector<size_t> jacobIndices(size_t n)
{
    if (n == 0)
        return std::vector<size_t>();

    std::vector<size_t> seq;
    std::vector<size_t> j;
    j.push_back(1);
    j.push_back(1);
    while (j.back() < n)
    {
        j.push_back(j[j.size() - 1] + 2 * j[j.size() - 2]);
    }

    size_t prev = 1;
    for (size_t k = 2; k < j.size(); ++k)
    {
        size_t cur = std::min(j[k], n);
        for (size_t i = cur; i > prev; --i)
            seq.push_back(i);
        prev = cur;
    }

    for (size_t i = n; i > prev; --i)
        seq.push_back(i);
    bool hasOne = false;
    for (size_t i = 0; i < seq.size(); ++i)
    {
        if (seq[i] == 1)
        {
            hasOne = true;
            break;
        }
    }
    if (!hasOne && n >= 1)
    {
        seq.push_back(1);
    }

    return seq;
}

std::vector<int> fjSort(const std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    std::vector<std::pair<int, int> > pairs;
    int leftover = 0;
    bool hasLeftover = false;

    for (size_t i = 0; i + 1 < arr.size(); i += 2)
    {
        int x = arr[i], y = arr[i + 1];
        if (x < y)
            std::swap(x, y);
        pairs.push_back(std::make_pair(x, y));
    }
    if (arr.size() % 2 != 0)
    {
        leftover = arr.back();
        hasLeftover = true;
    }

    std::vector<int> aVals;
    for (size_t i = 0; i < pairs.size(); ++i)
        aVals.push_back(pairs[i].first);
    std::vector<int> mainChain = fjSort(aVals);

    std::vector<int> result;
    if (!mainChain.empty())
    {
        int firstA = mainChain[0];
        int firstB = 0;
        for (size_t i = 0; i < pairs.size(); ++i)
            if (pairs[i].first == firstA)
            {
                firstB = pairs[i].second;
                break;
            }
        result.push_back(firstB);
        for (size_t i = 0; i < mainChain.size(); ++i)
            result.push_back(mainChain[i]);
    }

    std::vector<std::pair<int, size_t> > partnerPosVec;
    for (size_t i = 0; i < result.size(); ++i)
        partnerPosVec.push_back(std::make_pair(result[i], i));

    size_t firstPairIndex = pairs.size();
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].first == mainChain[0])
        {
            firstPairIndex = i;
            break; 
        }
    }

    std::vector<int> pendElements;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (i != firstPairIndex)
        {
            pendElements.push_back(pairs[i].second);
        }
    }

    if (hasLeftover)
    {
        pendElements.push_back(leftover);
    }

    if (pendElements.empty())
    {
        return result;
    }

    std::vector<size_t> insertionOrder = jacobIndices(pendElements.size());

    for (size_t k = 0; k < insertionOrder.size(); ++k)
    {
        size_t idx = insertionOrder[k] - 1;
        if (idx >= pendElements.size())
            continue;

        int elementToInsert = pendElements[idx];

        int partner = 0;
        bool hasPartner = false;

        if (hasLeftover && elementToInsert == leftover)
        {
            hasPartner = false;
        }
        else
        {
            for (size_t i = 0; i < pairs.size(); ++i)
            {
                if (pairs[i].second == elementToInsert && pairs[i].first != mainChain[0])
                {
                    partner = pairs[i].first;
                    hasPartner = true;
                    break;
                }
            }
        }

        size_t bound = result.size();
        if (hasPartner)
        {
            for (size_t i = 0; i < partnerPosVec.size(); ++i)
            {
                if (partnerPosVec[i].first == partner)
                {
                    bound = partnerPosVec[i].second;
                    break;
                }
            }
        }

        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.begin() + bound, elementToInsert);
        result.insert(pos, elementToInsert);

        partnerPosVec.clear();
        for (size_t i = 0; i < result.size(); ++i)
            partnerPosVec.push_back(std::make_pair(result[i], i));
    }

    return result;
}
