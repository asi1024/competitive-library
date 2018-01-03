module A = Array
module C = Char
module I = Int64
module L = List
module Q = Queue

let pf = Printf.printf
let sf = Scanf.scanf
let ssf = Scanf.sscanf

let read_int () = sf "%d " (fun x -> x)
let read_float () = sf "%f " (fun x -> x)
let read_array read n = A.init n (fun _ -> read ())
let err s = raise (Failure s)

let inf = int_of_float 1e18
let eps = 1e-11

module S = struct
  include String
  let of_array a = String.init (A.length a) (A.get a)
  let to_array s = A.init (String.length s) (String.get s)
end;;
