#include <iostream>
#include <vector>
#include <algorithm>
 
// ------------------------------------------------------------
// Jacobsthal number: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// ------------------------------------------------------------
int jacobsthal(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int tmp = b + 2 * a;
        a = b;
        b = tmp;
    }
    return b;
}
 
// ------------------------------------------------------------
// Build the Ford-Johnson insertion order (1-indexed b positions)
//
// Rule:
//   Generate Jacobsthal numbers J(1), J(2), J(3), ...
//   until J(k) >= pend_size.
//   Each new J(k) starts a group: insert from J(k) down to
//   J(k-1)+1  (i.e. count down to the previous Jacobsthal+1).
//   Stop including indices > pend_size.
//
//   The very first element (b1) is always inserted first
//   "for free" before this sequence, so the sequence starts
//   from the group that contains index 1, then 3,2, then 5,4,
//   then 11,10,9,8,7,6 ... etc.
// ------------------------------------------------------------
std::vector<int> buildInsertionOrder(int pend_size) {
    std::vector<int> order;
 
    if (pend_size == 0) return order;
 
    // b1 always goes first
    order.push_back(1);
 
    if (pend_size == 1) return order;
 
    // Walk through Jacobsthal groups starting at k=2
    // (J(2)=3 gives the first real group: 3,2)
    int k = 2;
    while (true) {
        int jk      = jacobsthal(k);
        int jk_prev = jacobsthal(k - 1);
 
        // The group covers indices jk down to jk_prev+1
        int group_start = std::min(jk, pend_size); // clamp to actual size
        int group_end   = jk_prev + 1;
 
        for (int idx = group_start; idx >= group_end; idx--) {
            if (idx <= pend_size)
                order.push_back(idx);
        }
 
        // Once J(k) covers or exceeds pend_size we are done
        if (jk >= pend_size) break;
 
        k++;
    }
 
    return order;
}
 
// ------------------------------------------------------------
// Demo: show pairs, pending chain, and full insertion order
// ------------------------------------------------------------
int main() {
    // Original input
    std::vector<int> input = {97, 115, 119, 98, 99, 122, 113, 110, 104, 102};
   // std::vector<int> input = {847, 392, 105, 678, 921, 56, 734, 289, 460, 812, 193, 574, 368, 999, 241, 670, 88, 715, 502, 349, 120, 955, 437, 681, 264, 790, 53, 826, 315, 908, 472, 619, 157, 843, 290, 731, 564, 982, 410, 275, 699, 34, 851, 223, 768, 599, 142, 907, 388, 621, 77, 455, 834, 266, 913, 548, 301, 694, 125, 872, 489, 250, 763, 910, 408, 662, 175, 5990, 521, 836, 92, 744, 317, 658, 481, 903, 229, 570, 346, 814, 67, 988, 432, 709, 284, 561, 798, 140, 623, 359, 875, 218, 946, 537, 660, 104, 722, 483, 591, 306};
    std::cout << "=== Ford-Johnson: Insertion Order Builder ===\n\n";
 
    // ---- Step 1: form adjacent pairs ----
    std::cout << "-- Step 1: Adjacent pairs (input order) --\n";
    std::vector<std::pair<int,int>> pairs; // (smaller=b, larger=a)
    for (size_t i = 0; i + 1 < input.size(); i += 2) {
        int lo = std::min(input[i], input[i+1]);
        int hi = std::max(input[i], input[i+1]);
        pairs.push_back({lo, hi});
        std::cout << "  pair " << (i/2 + 1) << ": (" << lo << ", " << hi << ")\n";
    }
    // handle odd element if any
    bool has_odd = input.size() % 2 != 0;
    int  odd_elem = has_odd ? input.back() : 0;
    if (has_odd)
        std::cout << "  straggler: " << odd_elem << "\n";
 
    // ---- Step 2: sort pairs by their larger element (a) ----
    std::stable_sort(pairs.begin(), pairs.end(),
                     [](const std::pair<int,int>& x, const std::pair<int,int>& y){
                         return x.second < y.second;
                     });
 
    std::cout << "\n-- Step 2: Pairs sorted by larger element --\n";
    for (size_t i = 0; i < pairs.size(); i++)
        std::cout << "  [" << i+1 << "] b=" << pairs[i].first
                  << "  a=" << pairs[i].second << "\n";
 
    // ---- Step 3: build main chain and pending chain ----
    std::vector<int> main_chain;
    std::vector<int> pend;
 
    for (auto& p : pairs)
        main_chain.push_back(p.second);   // all a's (already sorted)
 
    for (auto& p : pairs)
        pend.push_back(p.first);          // all b's in same order
 
    std::cout << "\n-- Step 3: Chains --\n";
    std::cout << "  main chain (a's): ";
    for (int x : main_chain) std::cout << x << " ";
    std::cout << "\n  pend      (b's): ";
    for (int x : pend)       std::cout << x << " ";
    std::cout << "\n";
 
    // ---- Step 4: compute insertion order ----
    int pend_size = (int)pend.size();
    std::vector<int> order = buildInsertionOrder(pend_size);
 
    std::cout << "\n-- Step 4: Jacobsthal-based insertion order (1-indexed b positions) --\n";
    std::cout << "  indices : ";
    for (int idx : order) std::cout << "b" << idx << " ";
    std::cout << "\n  values  : ";
    for (int idx : order) std::cout << pend[idx-1] << " ";
    std::cout << "\n";
 
    // ---- Step 5: actually insert using binary search ----
    std::cout << "\n-- Step 5: Binary-search insertions --\n";
 
    // b1 is inserted first (before a1, its partner)
    // Prepend b1 to main chain
    main_chain.insert(main_chain.begin(), pend[0]);
 
    std::cout << "  Insert b1=" << pend[0]
              << " at front (guaranteed <= a1)\n";
    std::cout << "  main: ";
    for (int x : main_chain) std::cout << x << " ";
    std::cout << "\n\n";
 
    // Insert the rest following the order (skip index 1, already done)
    for (size_t i = 1; i < order.size(); i++) {
        int b_idx   = order[i];          // 1-indexed position in pend
        int b_val   = pend[b_idx - 1];   // value to insert
        int a_val   = pairs[b_idx - 1].second; // its paired a (the upper bound)
 
        // Find a_val in current main_chain to get the bound
        auto bound_it = std::find(main_chain.begin(), main_chain.end(), a_val);
 
        // Binary search in [begin, bound_it] inclusive
        auto pos = std::lower_bound(main_chain.begin(), bound_it + 1, b_val);
 
        std::cout << "  Insert b" << b_idx << "=" << b_val
                  << "  (partner a" << b_idx << "=" << a_val << ")\n";
        std::cout << "  search range up to " << a_val
                  << " -> insert before position "
                  << std::distance(main_chain.begin(), pos) << "\n";
 
        main_chain.insert(pos, b_val);
 
        std::cout << "  main: ";
        for (int x : main_chain) std::cout << x << " ";
        std::cout << "\n\n";
    }
 
    // handle straggler (odd element) if any
    if (has_odd) {
        auto pos = std::lower_bound(main_chain.begin(), main_chain.end(), odd_elem);
        main_chain.insert(pos, odd_elem);
        std::cout << "  Insert straggler=" << odd_elem << "\n";
        std::cout << "  main: ";
        for (int x : main_chain) std::cout << x << " ";
        std::cout << "\n\n";
    }
 
    std::cout << "=== Final sorted result ===\n  ";
    for (int x : main_chain) std::cout << x << " ";
    std::cout << "\n";
 
    return 0;
}
