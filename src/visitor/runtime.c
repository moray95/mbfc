#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *malloc_s(size_t size)
{
  void *ptr = malloc(size);
  if (ptr == NULL)
  {
    fprintf(stderr, "Program out of memory");
    abort();
  }
  return ptr;
}

void *realloc_s(void *ptr, size_t size)
{
  void *tmp = realloc(ptr, size);
  if (tmp == NULL)
  {
    free(ptr);
    fprintf(stderr, "Program out of memory");
    abort();
  }
  return tmp;
}

#define malloc malloc_s
#define realloc realloc_s

struct context
{
  char* data;
  char* ptr;
  size_t size;
};

#define CONTEXT_MIN_SIZE 10000

void ctx_init(struct context *ctx)
{
  ctx->data = malloc(CONTEXT_MIN_SIZE * sizeof (char));
  memset(ctx->data, 0, CONTEXT_MIN_SIZE);
  ctx->size = CONTEXT_MIN_SIZE;
  ctx->ptr = ctx->data;
}

void ctx_free(struct context *ctx)
{
  free(ctx->data);
}

void ctx_inc_ptr(struct context *ctx)
{
  size_t ptr_offset = ctx->ptr - ctx->data;
  if (ctx->ptr == ctx->data + ctx->size - 1)
  {
    ctx->data = realloc(ctx->ptr, ctx->size * 2);
    memset(ctx->data + ctx->size, 0, ctx->size);
    ctx->size *= 2;
  }
  ctx->ptr = ctx->data + ptr_offset + 1;
}

void ctx_dec_ptr(struct context *ctx)
{
  if (ctx->data == ctx->ptr)
  {
    fprintf(stderr, "Pointer underflow");
    abort();
  }
  ctx->ptr--;
}

void ctx_inc_byte(struct context *ctx)
{
  (*(ctx->ptr))++;
}

void ctx_dec_byte(struct context *ctx)
{
  (*(ctx->ptr))--;
}

void ctx_in_byte(struct context *ctx)
{
  scanf("%c", ctx->ptr);
}

void ctx_out_byte(const struct context *ctx)
{
  putchar(*(ctx->ptr));
}

char ctx_get_byte(const struct context *ctx)
{
  return *(ctx->ptr);
}


