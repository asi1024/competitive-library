(*+ import include/template/template.ml +*)

let () =
  let x = sf "%d" (fun x -> x) in
  pf "%d\n" (x * x * x)
