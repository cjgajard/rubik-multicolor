# Rubik multi-color

Rubik cube with faces that mix their colors.

I was solving a cube when I wanted to know if it would be pretty to
have a cube where the color of non-central squares blend with its adjacent
colors. So I made this to have a better idea of how it would look. :-P

SPOILER ALERT! Like this:

![rubik](https://user-images.githubusercontent.com/12974475/62500376-153fa680-b7b4-11e9-93fb-844f7eda2f8d.png)

# Run

To print the faces in a 256color console:
```
gcc main.c render_stdio.c && ./a.out && rm a.out
```

To generate a `html` file (with 256-cubed colors):
```
gcc main.c render_html.c && ./a.out > index.html && rm a.out
```
