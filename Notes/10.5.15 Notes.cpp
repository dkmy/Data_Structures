10.5.15 notes


Max Subrun algo in O(n)


for (int i=0; i<n; ++i){
//	if (a[i] >= 0){
//		if (e>0){
//			e += a[i];
//		}
//		else{
//			e = a[i];
//		}
//	}
//	else if (a[i] + e > 0){
//		e += a[i];
//	}
//	else{
//		e=0;
//	}
//	if (b<e){
//		b = e;
//	}
//}
//return b;

	if (a[i] + e > 0){
		e += a[i];
	}
	else{
		e = 0;
	}
	if (b < e){
		b = e;
	}
	return b;
}


challenge problem by Dr. Aven

