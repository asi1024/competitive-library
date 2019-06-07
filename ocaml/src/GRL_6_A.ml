(*+ import ../include/template/template.ml +*)
(*+ import ../include/graph/max_flow.ml +*)

let () =
  let v = read_int () in
  let e = read_int () in
  let g = A.make v [] in
  for i = 0 to e - 1 do
    let u = read_int () in
    let v = read_int () in
    let c = read_int () in
    add_edge int_info g u v c
  done;
  let f = max_flow int_info g 0 (v - 1) in
  pf "%d\n" f
