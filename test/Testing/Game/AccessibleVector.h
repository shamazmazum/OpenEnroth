#pragma once

#include <cassert>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>

template<class Base>
class Accessible;

template<class T>
using AccessibleVector = Accessible<std::vector<T>>;

/**
 * Extension point for `delta` and `pairwiseDelta` methods of the `Accessible` classes. Effectively computes a delta
 * between `l` and 'r', i.e. `r - l`.
 *
 * This function is overloaded for `Accessible` classes, and it can also be overloaded for `std::tuple` / `std::pair`
 * if there comes a need to compute per-element deltas for them.
 *
 * @param l                             First value.
 * @param r                             Second value.
 * @return                              Delta between the first and the second value.
 */
template<class T>
T calculateDelta(const T &l, const T &r) {
    return r - l;
}

/**
 * Extension class that adds a couple methods to a container that makes writing tests easier.
 *
 * The methods themselves might remind you of what's available in Java 8 Stream API, or in `std::ranges`, but the
 * underlying implementation here is very dumb and doesn't even try to be fast. Every method allocates, so this class
 * isn't suitable for runtime usage - use `std::ranges` instead.
 *
 * Aside from the useful methods, `Accessible` also provides an `operator==` that makes it possible to compare
 * any two `Accessible` classes as long as their elements are comparable.
 *
 * @see AccessibleVector
 */
template<class Base>
class Accessible : public Base {
 public:
    using Base::Base;
    using Base::begin;
    using Base::end;
    using value_type = std::iter_value_t<decltype(std::declval<const Base *>()->begin())>;

    friend AccessibleVector<value_type> calculateDelta(const Accessible &l, const Accessible &r) {
        AccessibleVector<value_type> result;
        auto lpos = l.begin();
        auto rpos = r.begin();
        while (lpos != l.end())
            result.push_back(calculateDelta(*lpos++, *rpos++));
        assert(rpos == r.end());
        return result;
    }

    size_t size() const {
        return end() - begin();
    }

    const value_type &front() const {
        assert(begin() != end());
        return *begin();
    }

    const value_type &back() const {
        assert(begin() != end());
        return *std::prev(end());
    }

    AccessibleVector<value_type> frontBack() const {
        assert(begin() != end());
        return {front(), back()};
    }

    value_type delta() const {
        assert(begin() != end());
        return calculateDelta(front(), back());
    }

    AccessibleVector<value_type> adjacentDeltas() const {
        AccessibleVector<value_type> result;

        auto l0 = begin();
        auto r = end();
        if (l0 == r)
            return result;

        auto l1 = std::next(l0);
        while (l1 != r)
            result.push_back(calculateDelta(*l0++, *l1++));
        return result;
    }

    value_type min() const {
        assert(begin() != end());
        return *std::min_element(begin(), end());
    }

    value_type max() const {
        assert(begin() != end());
        return *std::max_element(begin(), end());
    }

    AccessibleVector<value_type> minMax() const {
        assert(begin() != end());
        auto pair = std::minmax_element(begin(), end());
        return {*pair.first, *pair.second};
    }

    auto flattened() const {
        using element_type = std::iter_value_t<decltype(std::declval<const value_type *>()->begin())>;
        AccessibleVector<element_type> result;
        for (const auto &chunk : *this)
            for (const auto &element : chunk)
                result.push_back(element);
        return result;
    }

    template<class Filter>
    AccessibleVector<value_type> filtered(Filter filter) const {
        AccessibleVector<value_type> result;
        std::copy_if(begin(), end(), std::back_inserter(result), std::move(filter));
        return result;
    }

    AccessibleVector<value_type> reversed() const {
        AccessibleVector<value_type> result;
        std::reverse_copy(begin(), end(), std::back_inserter(result));
        return result;
    }

    bool contains(const value_type &value) const {
        return std::find(begin(), end(), value) != end();
    }
};

template<class L, class R>
bool operator==(const Accessible<L> &l, const Accessible<R> &r) {
    return std::equal(l.begin(), l.end(), r.begin(), r.end());
}
