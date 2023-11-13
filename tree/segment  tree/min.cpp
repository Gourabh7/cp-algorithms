void build(int ind,int low,int high,vector<int>&arr,vector<int>&seg){
    if(low==high){
        seg[ind] = arr[low];
        return;
    }
    int mid = low+(high-low)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);

}
int query(int ind,int low,int high,int l,int r,vector<int>&arr,vector<int>&seg){
    if(low>r || high<l){
        return INT_MAX;
    }
    if(low>=l && high<=r){
        return seg[ind];
    }
    int mid = low+(high-low)/2;
    int left = query(2*ind+1,low,mid,l,r,arr,seg);
    int right  = query(2*ind+2,mid+1,high,l,r,arr,seg);
    return min(left,right);
}
void update(int ind,int low,int high,int i,int val,vector<int>&arr,vector<int>&seg){
    if(low==high){
        arr[i] = val;
        seg[ind] = val;
        return;
    }
    int mid = low+(high-low)/2;
    if(i<=mid)
    update(2*ind+1,low,mid,i,val,arr,seg);
    else
    update(2*ind+2,mid+1,high,i,val,arr,seg);
    seg[ind] = min(seg[2*ind+1],seg[2*ind+2]);
}
