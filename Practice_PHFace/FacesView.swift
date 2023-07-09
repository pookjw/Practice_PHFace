//
//  FacesView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/9/23.
//

import SwiftUI
import PhotosUI

struct FacesView: View {
    @State private var selectedPhotoPickerItems: [PhotosPickerItem] = .init()
    @State private var phFaces: [PHFace] = .init()
    
    var body: some View {
        List(phFaces, id: \.self) { phFace in
            Text(String(describing: phFace))
        }
            .toolbar {
                ToolbarItem(placement: .topBarTrailing) {
                    PhotosPicker(selection: $selectedPhotoPickerItems, matching: .images, photoLibrary: .shared()) {
                        Image(systemName: "photo")
                    }
                }
            }
            .navigationTitle("PHFace")
            .onChange(of: selectedPhotoPickerItems) { newValue in
                let itemItemtifiers: [String] = newValue
                    .compactMap { $0.itemIdentifier }
                let phAssets: PHFetchResult<PHAsset> = PHAsset.fetchAssets(withLocalIdentifiers: itemItemtifiers, options: nil)
                
                var phFaces: Set<PHFace> = .init()
                phAssets.enumerateObjects { phAsset, _, _ in
                    let _phFaces: PHFetchResult<PHFace> = PHFace.fetchFaces(inAsset: phAsset, options: nil) as! PHFetchResult<PHFace>
                    _phFaces.enumerateObjects { phFace, _, _ in
                        phFaces.insert(phFace)
                    }
                }
                
                self.phFaces = .init(phFaces)
            }
    }
}

#Preview {
    FacesView()
}
