# Lesson 10 confirmed: singly linked list, slot walk learned and questioned

On 2026-09-22 the user finished lesson 10 (`exercises/10-list/`).

## Evidence

- All eight list functions written by the user. Expected nine lines printed; `make check` 8 allocs, 8 frees, 0 errors. Agent-run extra cases for `list_reverse` (empty, one node, reversed three times) passed under ASan and UBSan.
- First `list_insert_sorted` had two real bugs the user could not see: `before->next` with `before == NULL` when v is smaller than the head, and `count` never updated anywhere. Both fixed from hints only.
- Second bug, self-inflicted while refactoring: the user merged the empty and smaller-than-head branches after an agent style note, but kept `new_node->next = NULL`, cutting the chain. The sanitizer build hid it (output looked right); the plain build printed `sorted: 0 9` and Valgrind showed 16 direct plus 48 indirect bytes lost. This is the lesson's third break case, met by accident. Fixed by the user.
- `list_remove` first written as prev/curr with a head special case, correct. The user then asked why `node_t**` is better, said it was "not as intuitive", and asked "so it doesn't require prev pointer most/all of the time?" Restated the idea correctly in their own words: with `curr` you have the node but not the pointer to it; with `node_t**` you hold that pointer's address all the time.
- Rewrote `list_remove` with the slot walk. Two errors on the way: loop body never advanced, then `link++` instead of `link = &(*link)->next`. Both fixed from one hint each. Final version correct on head, middle and absent value.
- The user still finds the slot walk "harder to understand and write" than prev/curr, and noted it has no equivalent in Python or Java. Told: normal, keep prev/curr as default, reach for the slot walk when a head special case appears; Java uses a sentinel node, Python and Java trees return the new head.
- Asked a good ownership question: why malloc nodes instead of storing `&local_node`. Answered with lifetime and ownership; the user did not push back.
- Break-it experiments 1 and 2 not reported as done. Not blocking.

## Implications

- The `node_t**` idiom is understood but not yet comfortable. Lesson 12 (BST insert without a parent pointer) is the natural second exposure; do not assume fluency there, re-draw the box picture once.
- Confirmed again: style suggestions to merge branches can introduce bugs when the user applies them without re-deriving. When suggesting a merge, state the one line that must change, not just "you can combine these".
- The plain build and `make check` caught what the sanitizer build did not. Keep both in every lesson's Done-when.
- Next is lesson 11, the linked queue.
