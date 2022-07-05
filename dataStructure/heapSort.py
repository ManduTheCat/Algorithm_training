

def hepify(unsorted , index, heap_size):
  largest = index
  left_index = 2 * index + 1
  right_index = 2 * index + 2
  if left_index < heap_size and unsorted[left_index] > unsorted[largest]:
    largest = left_index
  if right_index < heap_size and unsorted[right_index]> unsorted[largest]:
    largest = right_index
  if largest != index:
    unsorted[largest], unsorted[index] = unsorted[index], unsorted[largest]
    hepify(unsorted, index, heap_size)


def heap_sort(unsorted):
  len_unsorted = len(unsorted)
  for depth in range(len_unsorted//2, -1, -1):
    hepify(unsorted, depth, len_unsorted)


def main():
  data = [16,4,10,14,7,9,3,2,8,1]
  heap_sort(data)
  print(data)


if __name__ == "__main__":
  main()
