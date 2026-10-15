# 21. Merge Two Sorted Lists

- 문제 번호: 21
- 사이트: [LeetCode](https://leetcode.com/problems/merge-two-sorted-lists/)
- 난이도: Easy
- 폴더: `solutions/leetcode/easy/`

---

## 문제

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return *the head of the merged linked list*.

### 제한 사항 (Constraints)

- The number of nodes in both lists is in the range `[0, 50]`.
- `-100 <= Node.val <= 100`
- Both `list1` and `list2` are sorted in **non-decreasing** order.

### 입출력 예

- 입력
  - `list1`: {**ListNode\*** } 첫 번째 정렬된 연결 리스트
  - `list2`: {**ListNode\*** } 두 번째 정렬된 연결 리스트
- 출력
  - `return`: {**ListNode\*** } 병합되어 정렬된 연결 리스트의 헤드

### 예시

| 입력 (list1, list2)                  | 출력            |
|:-------------------------------------|:----------------|
| `list1 = [1,2,4]`, `list2 = [1,3,4]` | `[1,1,2,3,4,4]` |
| `list1 = []`, `list2 = []`           | `[]`            |
| `list1 = []`, `list2 = [0]`          | `[0]`           |

---

## 풀이 아이디어

1. **더미 노드(Dummy Node) 활용**: 병합 리스트의 시작점을 쉽게 관리하기 위해 더미 노드(`dummy`)를 생성하고 `head` 포인터로 연결해 나간다.
2. **양쪽 리스트 순회 및 비교**: 두 리스트 중 하나라도 노드가 남아있을 때까지 순회하며, 노드가 없는 리스트는 문제 제약조건(최댓값 100)보다 큰 값(`MAX_VALUE + 1`)으로 간주하여 더 작은 값을 가진 노드를 선택한다.
3. **노드 연결 및 포인터 이동**: 더 작은 값을 가진 노드를 `head->next`에 연결하고 해당 리스트 포인터와 `head` 포인터를 한 칸 전진시킨다.
4. **결과 반환**: `dummy->next`를 반환하여 병합된 연결 리스트의 헤드를 넘겨준다.

## 복잡도

- 시간: O(N + M) (N, M은 각각 `list1`, `list2`의 노드 수로, 모든 노드를 최대 한 번씩 방문)
- 공간: O(1) (새 노드를 생성하지 않고 기존 노드의 포인터만 재연결하므로 추가 공간은 O(1))

---

## 노트

- 문제의 제약 조건(`-100 <= Node.val <= 100`)을 활용하여 리스트가 끝난 경우 `MAX_VALUE + 1`을 부여함으로써 비교 분기를 일관되게 처리함.
- **개선**
  ```c++
    while (list1 != nullptr && list2 != nullptr) { // 두 LinkedList 중 하나만 끝에 도달하면 넘어감
      
      // 두 LinkedList 중 하나만 끝나면 되므로 길이 차이에 따른 nullptr 검사X
      // => MAX_VALUE 불필요
      if (val1 < val2) { 
        head->next = list1;
        list1 = list1->next;
      }
      else {
        head->next = list2;
        list2 = list2->next;
      }
      head = head->next;
    }
    
    // 사실 원래 존재했던 이 부분에서 위 처리를 모두 생략해줌
    if (list1 != nullptr) head->next = list1;
    if (list2 != nullptr) head->next = list2;
  ```
  - LinkedList는 각 원소끼리 포인터로 연결되어 있는 점을 이용하면 굳이 nullptr 검사하면서 두 LinkedList를 모두 순회할 필요가 없다.
  - 그러니까 하나의 서로 길이가 다른 두 LinkedList에서 하나의 LinkedList를 모두 순회 후, 남은 LinkedList를 그대로 포인터로 이어주는 방식으로 **성능적인 개선**할 수 있다.