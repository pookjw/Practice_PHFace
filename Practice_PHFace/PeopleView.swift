//
//  PeopleView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/9/23.
//

import SwiftUI
import PhotosUI

struct PeopleView: View {
    @State private var selectedPhotoPickerItems: [PhotosPickerItem] = .init()
    @State private var phPersons: [PHPerson] = .init()
    
    var body: some View {
        List(phPersons, id: \.self) { phPerson in
            Text(String(describing: phPerson))
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
                
                var phPersons: Set<PHPerson> = .init()
                phAssets.enumerateObjects { phAsset, _, _ in
                    let fetchResult: PHFetchResult<PHPerson> = PHPerson.fetchPersons(inAsset: phAsset, options: nil) as! PHFetchResult<PHPerson>
                    fetchResult.enumerateObjects { phPerson, _, _ in
                        print("keyFace: \(phPerson.keyFace())") // PHFace
                        phPersons.insert(phPerson)
                    }
                }
                
                self.phPersons = .init(phPersons)
            }
    }
}

#Preview {
    PeopleView()
}
