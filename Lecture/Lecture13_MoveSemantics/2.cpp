void PhotoCollection::insert(const Photo &pic, int pos)
{
    for (int i = size(); i > pos; i--)
        elems[i] = std::move(elems[i – 1]);
    elems[i] = pic;
}

void upload(Photo &&pic);
int main()
{
    upload(takePhoto());
}

void PhotoCollection::insert(const Photo &pic, int pos)
{
    2 for (int i = size(); i > pos; i--) 3 4 5
}


//第一次修改file
git add file
//第二次修改file
git add file

git commit -m"add"