---
title: "GRL_6_A.ml"
---
- [GitHub]({{ site.github.repository_url }}/blob/master/ocaml/src/GRL_6_A.ml)

### Includes

- [template.ml](../../include/template/template)
- [max_flow.ml](../../include/graph/max_flow)

{% highlight ocaml %}
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
{% endhighlight %}

[Back](..)
