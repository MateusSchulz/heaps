bool heapFull  (HEAP* heap)
{   if (heap->last == heap->maxSize-1)
      return true;
    else return false;  
}
