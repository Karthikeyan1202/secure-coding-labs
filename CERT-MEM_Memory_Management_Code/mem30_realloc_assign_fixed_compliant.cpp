#include <cstdlib>
#include <cstdio>

typedef struct { int count; int max; gdClipRectangle *list; } gdClip;
typedef struct { int x,y,w,h; } gdClipRectangle;
typedef struct { gdClip *clip; } gdImage;

void gdClipSetAdd(gdImage *im, gdClipRectangle *rect) {
    gdClipRectangle *more;
    if (im->clip == NULL) return;
    if (im->clip->count == im->clip->max) {
        more = (gdClipRectangle *)realloc(im->clip->list, (im->clip->max + 8) * sizeof(gdClipRectangle));
        if (more == 0) return;
        im->clip->max += 8;
        im->clip->list = more; /* assign back before use */
    }
    im->clip->list[im->clip->count] = *rect;
    im->clip->count++;
}

int main() {
    gdImage im;
    gdClip clip;
    gdClipRectangle rect = {0,0,100,100};
    clip.count = 0; clip.max = 8;
    clip.list = (gdClipRectangle*)malloc(clip.max * sizeof(gdClipRectangle));
    im.clip = &clip;
    gdClipSetAdd(&im, &rect);
    std::printf("Clip count: %d\n", im.clip->count);
    free(im.clip->list);
    return EXIT_SUCCESS;
}
