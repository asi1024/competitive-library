(*+ import include/template/template.ml +*)
(*+ import include/graph/dijkstra.ml +*)

let () =
  let v = read_int () in
  let e = read_int () in
  let r = read_int () in
  let g = Array.make v [] in
  for i = 0 to e - 1 do
    let s = read_int () in
    let t = read_int () in
    let d = read_int () in    
    add_edge g s t d
  done;
  let d = dijkstra int_info g r in
  for i = 0 to v - 1 do
    let res =
      if d.(i) = int_info.inf
      then "INF"
      else string_of_int d.(i) in
    print_endline res
  done
