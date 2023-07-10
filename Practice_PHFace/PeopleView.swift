//
//  PeopleView.swift
//  Practice_PHFace
//
//  Created by Jinwoo Kim on 7/9/23.
//

import SwiftUI
import PhotosUI

struct PeopleView: View {
    @Binding private var selectedPHPerson: PHPerson?
    @State private var selectedPhotoPickerItems: [PhotosPickerItem] = .init()
    @State private var phPersons: [PHPerson] = .init()
    
    init(selectedPHPerson: Binding<PHPerson?>) {
        _selectedPHPerson = selectedPHPerson
    }
    
    var body: some View {
        List(phPersons, id: \.self, selection: _selectedPHPerson) { phPerson in
            Text(phPerson.px_localIdentifier() as! String)
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
                        phPersons.insert(phPerson)
                    }
                }
                
                self.phPersons = .init(phPersons)
            }
    }
}

#Preview {
    PeopleView(selectedPHPerson: .constant(nil))
}
