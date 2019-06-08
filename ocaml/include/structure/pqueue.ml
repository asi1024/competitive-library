module PairingHeap = struct
  type 'a pqueue = EmptyPQueue | NodePQueue of ('a * 'a pqueue list)

  let merge l r = match (l, r) with
    | (EmptyPQueue, _) -> r
    | (_, EmptyPQueue) -> l
    | (NodePQueue (x, xs), NodePQueue (y, ys)) ->
       if x < y
       then NodePQueue (x, r :: xs)
       else NodePQueue (y, l :: ys)

  let rec mergelist = function
    | [] -> EmptyPQueue
    | x :: [] -> x
    | x :: y :: xs -> merge (merge x y) (mergelist xs)

  let empty = EmptyPQueue

  let singleton value = NodePQueue (value, [])

  let push value heap = merge (singleton value) heap

  let top = function
    | EmptyPQueue -> raise Not_found
    | NodePQueue (head, _) -> head

  let pop = function
    | EmptyPQueue -> raise Not_found
    | NodePQueue (_, tails) -> mergelist tails
end
;;
