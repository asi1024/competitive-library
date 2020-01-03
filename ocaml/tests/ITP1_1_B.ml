(*+ import ../include/template/template.ml +*)

let () =
  let x = read_int () in
  pf "%d\n" (x * x * x)
