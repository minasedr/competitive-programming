def has_cycle(head):
    store = set()
    while head:
        if head in store:
            return 1
        store.add(head)
        head = head.next
    return 0
