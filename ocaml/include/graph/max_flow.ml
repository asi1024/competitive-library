type 't edge = { s : int; t : int; cap : 't ref; rev : 't ref }
type 't graph = 't edge list array

let add_edge g s t cap zero =
  let cap = ref cap in
  let rev = ref zero in
  g.(s) <- { s = s; t = t; cap = cap; rev = rev } :: g.(s);
  g.(t) <- { s = t; t = s; cap = rev; rev = cap } :: g.(t)

let max_flow g s t zero inf plus minus =
  let v = Array.length g in
  let rec loop res =
    let d = Array.make v (-1) in
    let que = Queue.create () in
    d.(s) <- 0;
    Queue.push s que;
    while not (Queue.is_empty que) do
      let v = Queue.pop que in
      let update e =
        if !(e.cap) > zero && d.(e.t) < 0
        then (d.(e.t) <- d.(v) + 1; Queue.push e.t que) in
      List.iter update g.(v)
    done;
    if d.(t) < 0
    then res
    else let iter = Array.copy g in
         let rec augument v f =
           if v = t
           then f
           else let rec iter_loop () =
                  ( match iter.(v) with
                    | [] -> zero
                    | e :: new_iter ->
                       iter.(v) <- new_iter;
                       if !(e.cap) > zero && d.(v) < d.(e.t)
                       then let ff = augument e.t (min f !(e.cap)) in
                            if ff > zero
                            then ( e.cap := minus !(e.cap) ff;
                                   e.rev := plus !(e.rev) ff;
                                   ff )
                            else iter_loop ()
                       else iter_loop () ) in
                iter_loop () in
         let rec loop_augument res =
           let f = augument s inf in
           if f > zero then loop_augument (plus res f) else res in
         loop (loop_augument res) in
  loop zero
