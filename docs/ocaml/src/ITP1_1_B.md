## ITP1_1_B.ml

- [GitHub]({{ site.github.repository_url }}/blob/master/ocaml/src/ITP1_1_B.ml)

### Includes

- [template.ml](../include/template/template)

{% highlight ocaml %}
let () =
  let x = sf "%d" (fun x -> x) in
  pf "%d\n" (x * x * x)
{% endhighlight %}

[Back](../..)
